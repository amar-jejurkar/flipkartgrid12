import cv2
import serial

# Initialize the serial connection (change the port as needed)
ser = serial.Serial('COM6', 9600)  # COM3 is an example, you'll need to find your Arduino's port

# Initialize the camera (0 is the default camera, change it if needed)
cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    cv2.imshow('Video Feed', frame)

    # Perform computer vision operations here to detect objects or gestures

    key = cv2.waitKey(1) & 0xFF

    # Send commands to Arduino based on computer vision results
    if key == ord('a'):
        ser.write(b'A')
    elif key == ord('b'):
        ser.write(b'B')
    elif key == ord('c'):
        ser.write(b'C')
    elif key == ord('d'):
        ser.write(b'D')
    elif key == ord('e'):
        ser.write(b'E')
    elif key == ord('f'):
        ser.write(b'F')
    elif key == 27:  # Press 'Esc' to exit
        break

# Release resources
cap.release()
cv2.destroyAllWindows()
