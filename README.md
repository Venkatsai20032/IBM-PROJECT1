# IBM-PROJECT1


SMART WATER MANAGEMENT

1) Directly you can simulate this model by using this link : https://wokwi.com/projects/380553351208403969 
And should follow the steps provided in 3) THINGSPEAK and 4) REAL-TIME VIEWING PLATFORM which is below in this readme file


Or Otherwise to build this :

2) WOKWI:
First we should design the model which is in the image below:

![image](https://github.com/Venkatsai20032/IBM-PROJECT1/assets/146907358/9261edd0-2814-4c43-9744-329c26b7624e)

First Components Needed:
a) ESP32
b) Ultrasonic Sensor
c Potentiometer
d) VCC
e) GND

![image](https://github.com/Venkatsai20032/IBM-PROJECT1/assets/146907358/6cb9b29b-32f3-4ab5-98db-5e982941006b)



Connections:

Ultrasonic Sensor Connections:
i) Connect VCC of Ultrasonic Sensor to VCC which we added.
ii) Connect GNG of Ultrasonic Sensor to GND which we added.
iii) Connect TRIG of Ultrasonic Sensor to esp:26 in ESP32.
iv) Connect ECHO of Ultrasonic Sensor to esp:25 in ESP32.

![image](https://github.com/Venkatsai20032/IBM-PROJECT1/assets/146907358/cc47de69-0821-4901-9e25-1db979ba4500)


Potentiometer Connections:
i) Connect VCC of Potentiometer to esp:3V3 of ESP32.
ii) Connect GND of Potentiometer to esp:GND.2 of ESP32.
iii) Connect SIG of Potentiometer to esp:3 of ESP32.

![image](https://github.com/Venkatsai20032/IBM-PROJECT1/assets/146907358/e8932a3a-f849-4a36-aadd-18a858d7dc52)




Then we should use the sketch.ino file.
The diagram.json will be updated as we design the model in first step.
Then we should install needed libraries which is in libraries.txt.
We should change the CHANNEL ID and API_KEY of ThingSpeak in this code to your ThingSpeak channel's ID and API_KEY.

![image](https://github.com/Venkatsai20032/IBM-PROJECT1/assets/146907358/79dab2a9-7f76-4e52-b799-fcff55dcd650)



Then we can run the program .
And we can get output of the model.

![image](https://github.com/Venkatsai20032/IBM-PROJECT1/assets/146907358/39c7c4ef-8dc0-40a5-bfa9-82a06f332f38)

Here we get the water level output and ph value which tels whether the water is contaminated or not.

3) THINGSPEAK:
Then we want to open an account in ThingSpeak and should create a New Channel.
And Should create two fields named water level in CM and pH value.
![image](https://github.com/Venkatsai20032/IBM-PROJECT1/assets/146907358/695dec8a-ab3e-46d3-9556-55a368d5a28a)



We will connect the wokwi model to this ThingSpeak by using the CHANNEL ID and API_KEY of your ThingSpeak channel.
Then we want to run the Wokwi model and we will get the output data in ThingSpeak as Values and Graphs.

![image](https://github.com/Venkatsai20032/IBM-PROJECT1/assets/146907358/ca9b42fa-29e9-4383-ac35-08cb3f90ca7c)


4) REAL-TIME VIEWING PLATFORM:
First change the CHANNEL ID and API_KEY to your ThingSpeak channel in the index.html file ,and also use the background image which is named as Waterimage.jpg and then run the file.

![image](https://github.com/Venkatsai20032/IBM-PROJECT1/assets/146907358/02dc76a1-d0af-480c-9383-859f5402e993)



Then we will see two buttons which is Water Consumption Data and Contamination Level Data.

![image](https://github.com/Venkatsai20032/IBM-PROJECT1/assets/146907358/ed7e5a89-0753-498e-a485-86988ab48b2c)

When we click the Water Consumption Data button then we will get the value in centimetres.

![image](https://github.com/Venkatsai20032/IBM-PROJECT1/assets/146907358/b82c39ec-933f-4747-9018-78a76ed431fb)




When we click the Consumption Level Data button then we will get the output of pH value and it will tel whether the water is contaminated or not.

![image](https://github.com/Venkatsai20032/IBM-PROJECT1/assets/146907358/98d5212d-2e48-4df0-ae3a-b827ded4bef5)






