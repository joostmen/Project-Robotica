import cv2 as cv        #OpenCV module 
import numpy as np      #Wiskunde module 

#parameters meegeven
confThreshold = 0.5  #grens waarboven de match moet zijn om het te detecteren als persoon
nmsThreshold = 0.4   #Non-maximum suppression threshold, verlaagt overbodige bounding boxes die 
inpWidth = 320       #Width of network's input image
inpHeight = 320       #Height of network's input image

# Naamklassen laden
classesFile = "coco.names"
classes = None
with open(classesFile, 'rt') as f:
    classes = f.read().rstrip('\n').split('\n') #leest de classes file om vervolgens ze te kunnen linken aan de boxes

#YOLOv3 config files
modelConfiguration = "yolov3.cfg"
modelWeights = "yolov3.weights"


net = cv.dnn.readNetFromDarknet(modelConfiguration, modelWeights)   #leest deep neral network van de Darknet config met de instellingen van YOLOv3
net.setPreferableBackend(cv.dnn.DNN_BACKEND_OPENCV)                 #zet backend op OPENCV
net.setPreferableTarget(cv.dnn.DNN_TARGET_CPU)                      #Gebruikt alleen CPU (geen CUDA voor GPU)

#Functies
def getOutputsNames(net):       ##Definieert  outputlayers
    #pakt namen van output layers
    layersNames = net.getLayerNames()
    return [layersNames[i[0] - 1] for i in net.getUnconnectedOutLayers()]#getUnconnectedOutLayers is laatste layer


def drawPred(classId, conf, left, top, right, bottom):
    # Tekent de verwachtte bounding box
        #   rechthoek om object
    cv.rectangle(frame, (left, top), (right, bottom), (255, 178, 50), 3)
    center = (left + right) / 2     #middenpunt camera is inpWidth (op dit moment 320) 
    
    if classes:  
        assert(classId < len(classes))          	# controleert of de classes correct is voordat uitvoert
        label = '%s:%s' % (classes[classId], ('%.2f' % conf)) # zoekt naar class in coco.names en zet die in label + confidence

    #Positioneert de label
    labelSize, baseLine = cv.getTextSize(label, cv.FONT_HERSHEY_SIMPLEX, 0.5, 1)
    top = max(top, labelSize[1])
    if 'person' in label:      
        print(label + ' Left:' + str(left)  +' right: ' + str(right) + ' center: ' + str(center)) # print coords in terminal voor testen
        buffer = open('buffer.txt', 'w')
        buffer.write(str(center))
    cv.rectangle(frame, (left, top - round(1.5*labelSize[1])), (left + round(1.5*labelSize[0]), top + baseLine), (255, 255, 255), cv.FILLED)
    cv.putText(frame, label, (left, top), cv.FONT_HERSHEY_SIMPLEX, 0.75, (0,0,0), 1)

#Post Process wordt toegepast op de confidence d.m.v. non-maxima suppression
def postprocess(frame, outs):
    frameHeight = frame.shape[0]
    frameWidth = frame.shape[1]


    #Scant door alle bounding boxes heen om te kijken welke box de hoogste confidence heeft om vervolgens deze te tekenen.
    classIds = []
    confidences = []
    boxes = []
    for out in outs:
        for detection in out:   #Detection is die array met veel getalletjes
            scores = detection[5:]
            classId = np.argmax(scores)
            confidence = scores[classId]
            if confidence > confThreshold:
                center_x = int(detection[0] * frameWidth)
                center_y = int(detection[1] * frameHeight)

                width = int(detection[2] * frameWidth)
                height = int(detection[3] * frameHeight)
                left = int(center_x - width / 2)
                top = int(center_y - height / 2)
                classIds.append(classId)
                confidences.append(float(confidence))
                boxes.append([left, top, width, height])

    # doet nms om redundante boxes te elimineren
    indices = cv.dnn.NMSBoxes(boxes, confidences, confThreshold, nmsThreshold)
    for i in indices:
        i = i[0]
        box = boxes[i]
        left = box[0]
        top = box[1]
        width = box[2]
        height = box[3]
        drawPred(classIds[i], confidences[i], left, top, left + width, top + height)


# Process inputs
winName = 'Het oog van te Tijger'
cv.namedWindow(winName, cv.WINDOW_NORMAL)

outputFile = "Nightcore_Video_Resultaat.avi"    # de resultaten in een hogere fps dan opname waardoor er Nightcore onstaat
cap = cv.VideoCapture(0)

#Zet de vid_writer variabele zodat de video geoutput kan worden. TODO: Uitzetten wanneer langdurig aan houden(neemt gigaveel ruimte op)
vid_writer = cv.VideoWriter(outputFile, cv.VideoWriter_fourcc('M','J','P','G'), 30, (round(cap.get(cv.CAP_PROP_FRAME_WIDTH)),round(cap.get(cv.CAP_PROP_FRAME_HEIGHT))))

while cv.waitKey(1) < 0:    #wacht 1ms op buttonpress (returnt -1 als geen buttonpress)
    hasFrame, frame = cap.read()    #camera lezen

    blob = cv.dnn.blobFromImage(frame, 1/255, (inpWidth, inpHeight), [0,0,0], 1, crop=False) #  maak blob
    net.setInput(blob)  #stuurt blob as input voor YOLOv3

    outs = net.forward(getOutputsNames(net))    #forward 
    postprocess(frame, outs)    #Maakt een mooie bounding box

    vid_writer.write(frame.astype(np.uint8))
    cv.imshow(winName, frame)