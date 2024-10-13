# Smart Plant Monitoring System

This project is a **Smart Plant Monitoring System** developed using an **ESP32** microcontroller along with various sensors like the **DHT11**, **Ultrasonic Sensor**, **Soil Moisture Sensor**, and a **Blynk** app for monitoring plant health remotely.

### Features
- Monitors **temperature**, **humidity**, **soil moisture**, and **distance**.
- Automated **watering system** using a water pump.
- Real-time monitoring with **Blynk** app integration.
- Alerts using a **buzzer** for low water levels.

### Hardware Components
1. **ESP32 Microcontroller**  
2. **DHT11 Sensor** - Measures temperature and humidity  
3. **Ultrasonic Sensor** - Measures distance  
4. **Soil Moisture Sensor** - Monitors soil moisture  
5. **Water Pump** - Automatically waters the plant based on soil moisture level  
6. **LCD Display** - Shows real-time data from sensors  
7. **Buzzer** - Alerts for water levels  
8. **Blynk** - Mobile app dashboard for remote monitoring

### Software Components
1. **Arduino IDE** - Used for programming ESP32  
2. **Blynk** - Cloud platform for IoT integration  
3. **Fritzing** - Used for creating circuit diagrams  
4. **Draw.io** - Used for flowchart creation

### Circuit Diagrams and Flowcharts

#### Hardware Architecture
![Hardware Architecture](https://github.com/user-attachments/assets/dc4703c7-c4da-49fa-9244-440d5b4cae7e)

#### Circuit Diagram
![Circuit Diagram](https://github.com/user-attachments/assets/10d4aabc-6a0e-428e-850e-0015c3c224e5)


#### Flowchart
![Flowchart](https://github.com/user-attachments/assets/5c82832a-6ec0-4415-ae73-c8b670b9315b)


### System Development
- **ESP32 and DHT11 Connection**  
    <table>
    <tr>
      <th>Circuit Diagram</th>
      <th>Physical Image</th>
      <th>Code</th>
    </tr>
    <tr>
      <td><img src="https://github.com/Shishir3D/RoboticsCW/blob/main/docs_images/Picture3.png" alt="Circuit Diagram" width="300"/></td>
      <td><img src="https://github.com/Shishir3D/RoboticsCW/blob/main/docs_images/Picture2.png" alt="Physical Image" width="300"/></td>
      <td><img src="https://github.com/Shishir3D/RoboticsCW/blob/main/docs_images/Picture1.png" alt="Code" width="300"/></td>
    </tr>
    </table>

  
- **Connection of ESP32, DHT11, and LCD Display**  
    <table>
    <tr>
      <th>Circuit Diagram</th>
      <th>Physical Image</th>
      <th>Code</th>
    </tr>
    <tr>
      <td><img src="https://github.com/Shishir3D/RoboticsCW/blob/main/docs_images/Picture6.png" alt="Circuit Diagram" width="300"/></td>
      <td><img src="https://github.com/Shishir3D/RoboticsCW/blob/main/docs_images/Picture5.png" alt="Physical Image" width="300"/></td>
      <td><img src="https://github.com/Shishir3D/RoboticsCW/blob/main/docs_images/Picture4.png" alt="Code" width="300"/></td>
    </tr>
    </table>


- **Buzzer and Ultrasonic Sensor Connection**  
    <table>
    <tr>
      <th>Circuit Diagram</th>
      <th>Physical Image</th>
      <th>Code</th>
    </tr>
    <tr>
      <td><img src="https://github.com/Shishir3D/RoboticsCW/blob/main/docs_images/Picture9.png" alt="Circuit Diagram" width="300"/></td>
      <td><img src="https://github.com/Shishir3D/RoboticsCW/blob/main/docs_images/Picture8.png" alt="Physical Image" width="300"/></td>
      <td><img src="https://github.com/Shishir3D/RoboticsCW/blob/main/docs_images/Picture7.png" alt="Code" width="300"/></td>
    </tr>
    </table>

- **Connecting ESP32, Soil Moisture Sensor, LCD, and Water Pump**  
    <table>
    <tr>
      <th>Circuit Diagram</th>
      <th>Physical Image</th>
      <th>Code</th>
    </tr>
    <tr>
      <td><img src="https://github.com/Shishir3D/RoboticsCW/blob/main/docs_images/Picture15.png" alt="Circuit Diagram" width="300"/></td>
      <td><img src="https://github.com/Shishir3D/RoboticsCW/blob/main/docs_images/Picture14.png" alt="Physical Image" width="300"/></td>
      <td><img src="https://github.com/Shishir3D/RoboticsCW/blob/main/docs_images/Picture13.png" alt="Code" width="300"/></td>
    </tr>
    </table>


- **Final Connection with Blynk**  
    <table>
    <tr>
      <th>Circuit Diagram</th>
      <th>Physical Image</th>
      <th>Code</th>
    </tr>
    <tr>
      <td><img src="https://github.com/Shishir3D/RoboticsCW/blob/main/docs_images/Picture18.png" alt="Circuit Diagram" width="300"/></td>
      <td><img src="https://github.com/Shishir3D/RoboticsCW/blob/main/docs_images/Picture17.png" alt="Physical Image" width="300"/></td>
      <td><img src="https://github.com/Shishir3D/RoboticsCW/blob/main/docs_images/Picture16.png" alt="Code" width="300"/></td>
    </tr>
    </table>

### Test Cases
Test cases were run to verify the connections and functionality of the system. Below are the successful tests:

1. **ESP32 and DHT11** - Successfully reads temperature and humidity.  
   ![Test Case 1](link-to-figure-42)


3. **ESP32, DHT11, and LCD** - Temperature and humidity displayed correctly.  
   ![Test Case 2](link-to-figure-43)

4. **Buzzer and Ultrasonic Sensor** - Buzzer alerts at correct distance.  
   ![Test Case 3](link-to-figure-44)

5. **Water Pump Automation** - Water pump activates below 30% soil moisture.  
   ![Test Case 5](link-to-figure-46)

### Future Improvements
- **Capacitive moisture sensors** for better durability.
- **AI integration** to detect plant diseases using image recognition.
- **Automated water tank filling** with an ultrasonic sensor to prevent overflow.
- **Sprinkler system** to automate watering for larger areas.

### Final System Images
![Smart Plant Monitoring System](link-to-figure-47)
![Blynk Mobile Dashboard](link-to-figure-48)
