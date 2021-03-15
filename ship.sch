EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Ship schematic diagram"
Date "2020-12-14"
Rev "1.0"
Comp "XHD"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Module:Arduino_UNO_R3 A1
U 1 1 5F520893
P 3250 3600
F 0 "A1" H 3700 4750 50  0000 C CNN
F 1 "Arduino_UNO_R3" H 3900 4650 50  0000 C CNN
F 2 "Module:Arduino_UNO_R3" H 3250 3600 50  0001 C CIN
F 3 "https://www.arduino.cc/en/Main/arduinoBoardUno" H 3250 3600 50  0001 C CNN
	1    3250 3600
	-1   0    0    -1  
$EndComp
$Comp
L Device:LED D5
U 1 1 5F555FE7
P 7300 3750
F 0 "D5" V 7339 3632 50  0000 R CNN
F 1 "GREEN LIGHT" V 7248 3632 50  0000 R CNN
F 2 "" H 7300 3750 50  0001 C CNN
F 3 "~" H 7300 3750 50  0001 C CNN
	1    7300 3750
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R4
U 1 1 5F555FF1
P 7300 3150
F 0 "R4" H 7370 3196 50  0000 L CNN
F 1 "150" H 7370 3105 50  0000 L CNN
F 2 "" V 7230 3150 50  0001 C CNN
F 3 "~" H 7300 3150 50  0001 C CNN
	1    7300 3150
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D4
U 1 1 5F555FFB
P 7300 3450
F 0 "D4" V 7339 3332 50  0000 R CNN
F 1 "GREEN LIGHT" V 7248 3332 50  0000 R CNN
F 2 "" H 7300 3450 50  0001 C CNN
F 3 "~" H 7300 3450 50  0001 C CNN
	1    7300 3450
	0    -1   -1   0   
$EndComp
$Comp
L Device:Battery_Cell BT1
U 1 1 5F55E4CD
P 2100 4150
F 0 "BT1" H 1850 4250 50  0000 L CNN
F 1 "3.6V 18650 cell" H 2100 4350 50  0000 L CNN
F 2 "" V 2100 4210 50  0001 C CNN
F 3 "~" V 2100 4210 50  0001 C CNN
	1    2100 4150
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery_Cell BT2
U 1 1 5F577CA2
P 2100 4550
F 0 "BT2" H 1850 4600 50  0000 L CNN
F 1 "3.6V 18650 cell" H 2150 4450 50  0000 L CNN
F 2 "" V 2100 4610 50  0001 C CNN
F 3 "~" V 2100 4610 50  0001 C CNN
	1    2100 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 4250 2100 4350
Wire Wire Line
	2100 4650 2100 6250
Wire Wire Line
	3350 4700 3350 6250
Wire Wire Line
	3350 6250 2100 6250
Wire Wire Line
	2100 2250 3350 2250
Wire Wire Line
	2100 2250 2100 3950
Wire Wire Line
	3350 2600 3350 2250
$Comp
L power:GNDREF #PWR02
U 1 1 5FD857D9
P 2100 6450
F 0 "#PWR02" H 2100 6200 50  0001 C CNN
F 1 "GNDREF" H 2105 6277 50  0000 C CNN
F 2 "" H 2100 6450 50  0001 C CNN
F 3 "" H 2100 6450 50  0001 C CNN
	1    2100 6450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 6450 2100 6250
Connection ~ 2100 6250
$Comp
L power:VPP #PWR01
U 1 1 5FD873EF
P 2100 2250
F 0 "#PWR01" H 2100 2100 50  0001 C CNN
F 1 "VPP" H 2115 2423 50  0000 C CNN
F 2 "" H 2100 2250 50  0001 C CNN
F 3 "" H 2100 2250 50  0001 C CNN
	1    2100 2250
	1    0    0    -1  
$EndComp
Connection ~ 2100 2250
$Comp
L power:VPP #PWR04
U 1 1 5FD87824
P 7300 2950
F 0 "#PWR04" H 7300 2800 50  0001 C CNN
F 1 "VPP" H 7315 3123 50  0000 C CNN
F 2 "" H 7300 2950 50  0001 C CNN
F 3 "" H 7300 2950 50  0001 C CNN
	1    7300 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 3000 7300 2950
$Comp
L Device:R R?
U 1 1 60377530
P 6850 4200
F 0 "R?" V 6643 4200 50  0000 C CNN
F 1 "10K" V 6734 4200 50  0000 C CNN
F 2 "" V 6780 4200 50  0001 C CNN
F 3 "~" H 6850 4200 50  0001 C CNN
	1    6850 4200
	0    1    1    0   
$EndComp
$Comp
L power:GNDREF #PWR?
U 1 1 6037753A
P 7300 4500
F 0 "#PWR?" H 7300 4250 50  0001 C CNN
F 1 "GNDREF" H 7305 4327 50  0000 C CNN
F 2 "" H 7300 4500 50  0001 C CNN
F 3 "" H 7300 4500 50  0001 C CNN
	1    7300 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 4400 7300 4500
$Comp
L Transistor_BJT:BC547 Q?
U 1 1 60377545
P 7200 4200
F 0 "Q?" H 7390 4246 50  0000 L CNN
F 1 "2N2222" H 7390 4155 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 7400 4125 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC547.pdf" H 7200 4200 50  0001 L CNN
	1    7200 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 4000 7300 3900
Text Label 5250 4200 0    50   ~ 0
GREENLIGHTS
Wire Wire Line
	3750 4200 6700 4200
$Comp
L Motor:Motor_Servo M?
U 1 1 605230FB
P 6250 2200
F 0 "M?" H 6582 2265 50  0000 L CNN
F 1 "servoX" H 6582 2174 50  0000 L CNN
F 2 "" H 6250 2010 50  0001 C CNN
F 3 "http://forums.parallax.com/uploads/attachments/46831/74481.png" H 6250 2010 50  0001 C CNN
	1    6250 2200
	1    0    0    -1  
$EndComp
$Comp
L Motor:Motor_Servo M?
U 1 1 60524CFE
P 6250 2650
F 0 "M?" H 6582 2715 50  0000 L CNN
F 1 "servoY" H 6582 2624 50  0000 L CNN
F 2 "" H 6250 2460 50  0001 C CNN
F 3 "http://forums.parallax.com/uploads/attachments/46831/74481.png" H 6250 2460 50  0001 C CNN
	1    6250 2650
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery_Cell BT?
U 1 1 605259A5
P 4750 2550
F 0 "BT?" H 4500 2650 50  0000 L CNN
F 1 "3.6V 18650 cell" H 4050 2750 50  0000 L CNN
F 2 "" V 4750 2610 50  0001 C CNN
F 3 "~" V 4750 2610 50  0001 C CNN
	1    4750 2550
	1    0    0    -1  
$EndComp
$Comp
L power:GNDREF #PWR?
U 1 1 6052C1C5
P 4750 2750
F 0 "#PWR?" H 4750 2500 50  0001 C CNN
F 1 "GNDREF" H 4755 2577 50  0000 C CNN
F 2 "" H 4750 2750 50  0001 C CNN
F 3 "" H 4750 2750 50  0001 C CNN
	1    4750 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 2750 4750 2650
Wire Wire Line
	5950 2650 5400 2650
Wire Wire Line
	5400 2650 5400 2200
Wire Wire Line
	5400 2200 5950 2200
$Comp
L power:GNDREF #PWR?
U 1 1 6052DF26
P 5900 2300
F 0 "#PWR?" H 5900 2050 50  0001 C CNN
F 1 "GNDREF" V 6000 2100 50  0000 C CNN
F 2 "" H 5900 2300 50  0001 C CNN
F 3 "" H 5900 2300 50  0001 C CNN
	1    5900 2300
	0    1    1    0   
$EndComp
$Comp
L power:GNDREF #PWR?
U 1 1 6052E7BC
P 5900 2750
F 0 "#PWR?" H 5900 2500 50  0001 C CNN
F 1 "GNDREF" V 6000 2550 50  0000 C CNN
F 2 "" H 5900 2750 50  0001 C CNN
F 3 "" H 5900 2750 50  0001 C CNN
	1    5900 2750
	0    1    1    0   
$EndComp
Wire Wire Line
	5900 2750 5950 2750
Wire Wire Line
	5900 2300 5950 2300
Wire Wire Line
	5950 2100 3900 2100
Wire Wire Line
	3900 2100 3900 3000
Wire Wire Line
	5950 2550 5250 2550
Wire Wire Line
	5250 2550 5250 3100
Wire Wire Line
	4750 2350 4750 2200
Wire Wire Line
	4750 2200 5400 2200
Connection ~ 5400 2200
Wire Wire Line
	3750 3000 3900 3000
Wire Wire Line
	3750 3100 5250 3100
$EndSCHEMATC
