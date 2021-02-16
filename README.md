# Servo Laser Pointer Turret
 Arduino based laser pointer turret that you control with your mouse.

# Materials needed
1x Arduino (any kind, tested with Uno) <br>
2x Servo (tested with both 9g and high torque servos)<br>
1x Computer (optimally with Visual Studio installed)

# Build Instructions
These instructions will give you a pretty ugly result, but it will work fine. Just base your own designs off of this example.
1. Glue one servo to a heavy object (for example a metal box or can). This is our Y-rotation.
2. Glue the other servo on top of the first servo, laying on it's side. This will be our X-rotation.
3. Glue the laser pointer onto the side of the top servo, so that when the top servo rotates, the laser pointer points up and down, and when the bottom servo rotates, the laser pointer points from side to side.
4. Done!

# Wiring
Connect the servos 5V and GND (Brown and Red) to the 5V and GND headers on your Arduino.
Connect the signal wires as such:
<br>
X-Axis: D10
<br>
Y-Axis: D11
<br>
These pins can be changed in the supplied .ino easily.

# How to use
1. Flash the Arduino sketch to your arduino using the .ino file provided.
2. Open the visual studio project, or the provided .exe (make sure your Arduino is connected to COM7 if you plan to use the prebaked .exe!)
3. Open the Visual Studio project, and double click "Form1.cs" to customize the code.
4. In Visual Studio, click on "port" under the window, and change the "PortName" to the one your Arduino is connected to (you can see this in the Arduino IDE, under Tools > Port).
5. Run the code.
6. If you did everything right you should now be able to pan and tilt the turret by moving your mouse around the window.
7. If one direction (for example X) is mirrored, go into Visual Studio, and put a "180 - " before either "coordinates.X" or "coordinates.Y" (Line 44 and 45).