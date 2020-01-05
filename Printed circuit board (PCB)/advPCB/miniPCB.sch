EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_ST_STM32F0:STM32F051R8Tx U1
U 1 1 5DDC96B4
P 5300 3350
F 0 "U1" H 5300 1461 50  0000 C CNN
F 1 "STM32F051R8Tx" H 5300 1370 50  0000 C CNN
F 2 "Package_QFP:LQFP-64_10x10mm_P0.5mm" H 4800 1650 50  0001 R CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/DM00039193.pdf" H 5300 3350 50  0001 C CNN
	1    5300 3350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5DDD0E8A
P 5250 5750
F 0 "#PWR0101" H 5250 5500 50  0001 C CNN
F 1 "GND" H 5255 5577 50  0000 C CNN
F 2 "" H 5250 5750 50  0001 C CNN
F 3 "" H 5250 5750 50  0001 C CNN
	1    5250 5750
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5DDCCA5E
P 2100 1250
F 0 "R1" H 2170 1296 50  0000 L CNN
F 1 "40000" H 2170 1205 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2030 1250 50  0001 C CNN
F 3 "~" H 2100 1250 50  0001 C CNN
	1    2100 1250
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C1
U 1 1 5DDCD30B
P 2600 1900
F 0 "C1" H 2715 1946 50  0000 L CNN
F 1 "100nF" H 2715 1855 50  0000 L CNN
F 2 "Capacitor_THT:C_Axial_L3.8mm_D2.6mm_P7.50mm_Horizontal" H 2638 1750 50  0001 C CNN
F 3 "~" H 2600 1900 50  0001 C CNN
	1    2600 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 1750 2600 1650
Wire Wire Line
	5250 5650 5250 5750
Wire Wire Line
	5200 5150 5200 5650
Wire Wire Line
	5200 5650 5250 5650
Wire Wire Line
	5250 5650 5300 5650
Wire Wire Line
	5400 5650 5400 5150
Connection ~ 5250 5650
Wire Wire Line
	5300 5150 5300 5650
Connection ~ 5300 5650
Wire Wire Line
	5300 5650 5400 5650
$Comp
L Device:R_POT_US RV1
U 1 1 5DE09742
P 9050 3550
F 0 "RV1" H 8983 3596 50  0000 R CNN
F 1 "R_POT_US" H 8983 3505 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Alps_RK09K_Single_Vertical" H 9050 3550 50  0001 C CNN
F 3 "~" H 9050 3550 50  0001 C CNN
	1    9050 3550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5DE2611F
P 4700 1950
F 0 "#PWR0102" H 4700 1700 50  0001 C CNN
F 1 "GND" H 4705 1777 50  0000 C CNN
F 2 "" H 4700 1950 50  0001 C CNN
F 3 "" H 4700 1950 50  0001 C CNN
	1    4700 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 2350 5900 2350
$Comp
L Switch:SW_Push SW1
U 1 1 5DE1D95A
P 1700 1950
F 0 "SW1" H 1700 2235 50  0000 C CNN
F 1 "SW_Push" H 1700 2144 50  0000 C CNN
F 2 "Button_Switch_THT:SW_Tactile_Straight_KSA0Axx1LFTR" H 1700 2150 50  0001 C CNN
F 3 "~" H 1700 2150 50  0001 C CNN
	1    1700 1950
	0    -1   -1   0   
$EndComp
Text GLabel 4700 1750 0    50   Input ~ 0
NRST
Text GLabel 2800 1650 2    50   Input ~ 0
NRST
Connection ~ 2600 1650
Wire Wire Line
	2600 1650 2800 1650
Wire Wire Line
	1700 1250 1700 1650
Wire Wire Line
	1700 1250 1950 1250
Wire Wire Line
	1700 1650 2600 1650
Connection ~ 1700 1650
Wire Wire Line
	1700 1650 1700 1750
$Comp
L power:GND #PWR0103
U 1 1 5DE85CBA
P 2150 2400
F 0 "#PWR0103" H 2150 2150 50  0001 C CNN
F 1 "GND" H 2155 2227 50  0000 C CNN
F 2 "" H 2150 2400 50  0001 C CNN
F 3 "" H 2150 2400 50  0001 C CNN
	1    2150 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 2150 1700 2400
Wire Wire Line
	1700 2400 2150 2400
Wire Wire Line
	2600 2400 2150 2400
Wire Wire Line
	2600 2050 2600 2400
Connection ~ 2150 2400
$Comp
L Switch:SW_Push SW2
U 1 1 5DEB72F7
P 7600 1450
F 0 "SW2" H 7600 1735 50  0000 C CNN
F 1 "SW_Push" H 7600 1644 50  0000 C CNN
F 2 "Button_Switch_THT:SW_Tactile_Straight_KSA0Axx1LFTR" H 7600 1650 50  0001 C CNN
F 3 "~" H 7600 1650 50  0001 C CNN
	1    7600 1450
	0    -1   -1   0   
$EndComp
Text GLabel 7500 1750 0    50   Input ~ 0
PA6
Wire Wire Line
	7600 1650 7600 1750
Wire Wire Line
	7600 1750 7500 1750
Text GLabel 6000 2350 2    50   Input ~ 0
PA6
Text GLabel 6000 2450 2    50   Input ~ 0
PA7
Wire Wire Line
	6000 2450 5900 2450
$Comp
L Connector:Conn_01x20_Female J7
U 1 1 5DF2E12C
P 10000 4250
F 0 "J7" H 10028 4226 50  0000 L CNN
F 1 "Conn_01x20_Female" H 10028 4135 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x20_P2.54mm_Vertical" H 10000 4250 50  0001 C CNN
F 3 "~" H 10000 4250 50  0001 C CNN
	1    10000 4250
	1    0    0    -1  
$EndComp
Text GLabel 9800 3650 0    50   Input ~ 0
PB0
Text GLabel 9800 3750 0    50   Input ~ 0
PB1
Text GLabel 9800 3850 0    50   Input ~ 0
PB2
Text GLabel 9800 3950 0    50   Input ~ 0
PB3
Text GLabel 9800 4050 0    50   Input ~ 0
PB4
Text GLabel 9800 4150 0    50   Input ~ 0
PB5
Text GLabel 9800 4250 0    50   Input ~ 0
PB6
Text GLabel 9800 4350 0    50   Input ~ 0
PB7
Text GLabel 9800 4450 0    50   Input ~ 0
PB8
Text GLabel 9800 4550 0    50   Input ~ 0
PB9
Text GLabel 9800 4650 0    50   Input ~ 0
PB10
Text GLabel 9800 4750 0    50   Input ~ 0
PB11
Text GLabel 9800 4850 0    50   Input ~ 0
PB12
Text GLabel 9800 4950 0    50   Input ~ 0
PB13
Text GLabel 5900 3450 2    50   Input ~ 0
PB0
Text GLabel 5900 3550 2    50   Input ~ 0
PB1
Text GLabel 5900 3650 2    50   Input ~ 0
PB2
Text GLabel 5900 3750 2    50   Input ~ 0
PB3
Text GLabel 5900 3850 2    50   Input ~ 0
PB4
Text GLabel 5900 3950 2    50   Input ~ 0
PB5
Text GLabel 5900 4050 2    50   Input ~ 0
PB6
Text GLabel 5900 4150 2    50   Input ~ 0
PB7
Text GLabel 5900 4250 2    50   Input ~ 0
PB8
Text GLabel 5900 4350 2    50   Input ~ 0
PB9
Text GLabel 5900 4450 2    50   Input ~ 0
PB10
Text GLabel 5900 4550 2    50   Input ~ 0
PB11
Text GLabel 5900 4650 2    50   Input ~ 0
PB12
Text GLabel 5900 4750 2    50   Input ~ 0
PB13
Wire Wire Line
	9800 3550 9350 3550
$Comp
L power:+5V #PWR0106
U 1 1 5DF65359
P 9050 3200
F 0 "#PWR0106" H 9050 3050 50  0001 C CNN
F 1 "+5V" H 9065 3373 50  0000 C CNN
F 2 "" H 9050 3200 50  0001 C CNN
F 3 "" H 9050 3200 50  0001 C CNN
	1    9050 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 3200 9050 3400
$Comp
L power:GND #PWR0107
U 1 1 5DF66459
P 9800 3450
F 0 "#PWR0107" H 9800 3200 50  0001 C CNN
F 1 "GND" V 9805 3322 50  0000 R CNN
F 2 "" H 9800 3450 50  0001 C CNN
F 3 "" H 9800 3450 50  0001 C CNN
	1    9800 3450
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR0108
U 1 1 5DF670EB
P 9500 3200
F 0 "#PWR0108" H 9500 3050 50  0001 C CNN
F 1 "+5V" H 9515 3373 50  0000 C CNN
F 2 "" H 9500 3200 50  0001 C CNN
F 3 "" H 9500 3200 50  0001 C CNN
	1    9500 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	9800 3350 9500 3350
Wire Wire Line
	9500 3350 9500 3200
$Comp
L power:GND #PWR0109
U 1 1 5DF76008
P 9800 5250
F 0 "#PWR0109" H 9800 5000 50  0001 C CNN
F 1 "GND" H 9805 5077 50  0000 C CNN
F 2 "" H 9800 5250 50  0001 C CNN
F 3 "" H 9800 5250 50  0001 C CNN
	1    9800 5250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5DF87850
P 7600 900
F 0 "R2" H 7670 946 50  0000 L CNN
F 1 "R" H 7670 855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7530 900 50  0001 C CNN
F 3 "~" H 7600 900 50  0001 C CNN
	1    7600 900 
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5DF87E7F
P 7600 2000
F 0 "R3" H 7670 2046 50  0000 L CNN
F 1 "R" H 7670 1955 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7530 2000 50  0001 C CNN
F 3 "~" H 7600 2000 50  0001 C CNN
	1    7600 2000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C5
U 1 1 5DF91BC2
P 7950 1450
F 0 "C5" H 8065 1496 50  0000 L CNN
F 1 "C" H 8065 1405 50  0000 L CNN
F 2 "Capacitor_THT:C_Axial_L3.8mm_D2.6mm_P7.50mm_Horizontal" H 7988 1300 50  0001 C CNN
F 3 "~" H 7950 1450 50  0001 C CNN
	1    7950 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 1600 7950 1950
$Comp
L power:GND #PWR0110
U 1 1 5DF930FC
P 7950 1950
F 0 "#PWR0110" H 7950 1700 50  0001 C CNN
F 1 "GND" H 7955 1777 50  0000 C CNN
F 2 "" H 7950 1950 50  0001 C CNN
F 3 "" H 7950 1950 50  0001 C CNN
	1    7950 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 1750 7600 1850
Connection ~ 7600 1750
$Comp
L power:GND #PWR0111
U 1 1 5DF96297
P 7600 2150
F 0 "#PWR0111" H 7600 1900 50  0001 C CNN
F 1 "GND" H 7605 1977 50  0000 C CNN
F 2 "" H 7600 2150 50  0001 C CNN
F 3 "" H 7600 2150 50  0001 C CNN
	1    7600 2150
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW3
U 1 1 5DF9E703
P 9000 1400
F 0 "SW3" H 9000 1685 50  0000 C CNN
F 1 "SW_Push" H 9000 1594 50  0000 C CNN
F 2 "Button_Switch_THT:SW_Tactile_Straight_KSA0Axx1LFTR" H 9000 1600 50  0001 C CNN
F 3 "~" H 9000 1600 50  0001 C CNN
	1    9000 1400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9000 1600 9000 1700
Wire Wire Line
	9000 1700 8900 1700
$Comp
L Device:R R4
U 1 1 5DF9E712
P 9000 900
F 0 "R4" H 9070 946 50  0000 L CNN
F 1 "R" H 9070 855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 8930 900 50  0001 C CNN
F 3 "~" H 9000 900 50  0001 C CNN
	1    9000 900 
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 5DF9E718
P 9000 1950
F 0 "R5" H 9070 1996 50  0000 L CNN
F 1 "R" H 9070 1905 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 8930 1950 50  0001 C CNN
F 3 "~" H 9000 1950 50  0001 C CNN
	1    9000 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:C C6
U 1 1 5DF9E71E
P 9350 1550
F 0 "C6" H 9465 1596 50  0000 L CNN
F 1 "C" H 9465 1505 50  0000 L CNN
F 2 "Capacitor_THT:C_Axial_L3.8mm_D2.6mm_P7.50mm_Horizontal" H 9388 1400 50  0001 C CNN
F 3 "~" H 9350 1550 50  0001 C CNN
	1    9350 1550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0113
U 1 1 5DF9E726
P 9350 1900
F 0 "#PWR0113" H 9350 1650 50  0001 C CNN
F 1 "GND" H 9355 1727 50  0000 C CNN
F 2 "" H 9350 1900 50  0001 C CNN
F 3 "" H 9350 1900 50  0001 C CNN
	1    9350 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	9000 1700 9000 1800
Connection ~ 9000 1700
$Comp
L power:GND #PWR0114
U 1 1 5DF9E72E
P 9000 2100
F 0 "#PWR0114" H 9000 1850 50  0001 C CNN
F 1 "GND" H 9005 1927 50  0000 C CNN
F 2 "" H 9000 2100 50  0001 C CNN
F 3 "" H 9000 2100 50  0001 C CNN
	1    9000 2100
	1    0    0    -1  
$EndComp
Text GLabel 8900 1700 0    50   Input ~ 0
PA7
Wire Wire Line
	9800 5150 9600 5150
$Comp
L Device:D D1
U 1 1 5DFA94D5
P 9450 5150
F 0 "D1" H 9450 4934 50  0000 C CNN
F 1 "D" H 9450 5025 50  0000 C CNN
F 2 "Diode_THT:D_5W_P10.16mm_Horizontal" H 9450 5150 50  0001 C CNN
F 3 "~" H 9450 5150 50  0001 C CNN
	1    9450 5150
	-1   0    0    1   
$EndComp
Wire Wire Line
	8950 5150 9300 5150
$Comp
L power:+5V #PWR0115
U 1 1 5DFAAEDD
P 8950 5150
F 0 "#PWR0115" H 8950 5000 50  0001 C CNN
F 1 "+5V" V 8965 5278 50  0000 L CNN
F 2 "" H 8950 5150 50  0001 C CNN
F 3 "" H 8950 5150 50  0001 C CNN
	1    8950 5150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9350 3550 9350 5050
Wire Wire Line
	9350 5050 9800 5050
Connection ~ 9350 3550
Wire Wire Line
	9350 3550 9200 3550
Wire Wire Line
	9050 3700 9050 3900
$Comp
L power:GND #PWR0116
U 1 1 5DFACF25
P 9050 3900
F 0 "#PWR0116" H 9050 3650 50  0001 C CNN
F 1 "GND" H 9055 3727 50  0000 C CNN
F 2 "" H 9050 3900 50  0001 C CNN
F 3 "" H 9050 3900 50  0001 C CNN
	1    9050 3900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5DFAF26A
P 2800 5850
F 0 "C2" H 2915 5896 50  0000 L CNN
F 1 "C" H 2915 5805 50  0000 L CNN
F 2 "Capacitor_THT:C_Radial_D6.3mm_H5.0mm_P2.50mm" H 2838 5700 50  0001 C CNN
F 3 "~" H 2800 5850 50  0001 C CNN
	1    2800 5850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 5DFB0285
P 3100 5850
F 0 "C3" H 3215 5896 50  0000 L CNN
F 1 "C" H 3215 5805 50  0000 L CNN
F 2 "Capacitor_THT:C_Radial_D6.3mm_H5.0mm_P2.50mm" H 3138 5700 50  0001 C CNN
F 3 "~" H 3100 5850 50  0001 C CNN
	1    3100 5850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 5DFB09CF
P 3400 5850
F 0 "C4" H 3515 5896 50  0000 L CNN
F 1 "C" H 3515 5805 50  0000 L CNN
F 2 "Capacitor_THT:C_Radial_D6.3mm_H5.0mm_P2.50mm" H 3438 5700 50  0001 C CNN
F 3 "~" H 3400 5850 50  0001 C CNN
	1    3400 5850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0117
U 1 1 5DFB1156
P 3100 6400
F 0 "#PWR0117" H 3100 6150 50  0001 C CNN
F 1 "GND" H 3105 6227 50  0000 C CNN
F 2 "" H 3100 6400 50  0001 C CNN
F 3 "" H 3100 6400 50  0001 C CNN
	1    3100 6400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 5700 3400 5700
Wire Wire Line
	3100 5700 2800 5700
Connection ~ 3100 5700
Wire Wire Line
	2800 6000 3100 6000
Wire Wire Line
	3400 6000 3100 6000
Connection ~ 3100 6000
Wire Wire Line
	3100 6000 3100 6400
Wire Wire Line
	1800 4900 1900 4900
Wire Wire Line
	1900 4900 1900 4950
Wire Wire Line
	1900 5000 1800 5000
$Comp
L power:GND #PWR0118
U 1 1 5DFB9287
P 1900 4950
F 0 "#PWR0118" H 1900 4700 50  0001 C CNN
F 1 "GND" V 1905 4822 50  0000 R CNN
F 2 "" H 1900 4950 50  0001 C CNN
F 3 "" H 1900 4950 50  0001 C CNN
	1    1900 4950
	0    -1   -1   0   
$EndComp
Connection ~ 1900 4950
Wire Wire Line
	1900 4950 1900 5000
Wire Wire Line
	1400 5350 1400 5300
Wire Wire Line
	1500 5300 1500 5350
Wire Wire Line
	1500 5350 1400 5350
$Comp
L power:GND #PWR0120
U 1 1 5DFBCF01
P 1400 5350
F 0 "#PWR0120" H 1400 5100 50  0001 C CNN
F 1 "GND" H 1405 5177 50  0000 C CNN
F 2 "" H 1400 5350 50  0001 C CNN
F 3 "" H 1400 5350 50  0001 C CNN
	1    1400 5350
	1    0    0    -1  
$EndComp
Connection ~ 1400 5350
$Comp
L Connector:Conn_01x01_Female J2
U 1 1 5DFBE4F3
P 1550 3300
F 0 "J2" H 1578 3326 50  0000 L CNN
F 1 "Conn_01x01_Female" H 1578 3235 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x01_P2.54mm_Vertical" H 1550 3300 50  0001 C CNN
F 3 "~" H 1550 3300 50  0001 C CNN
	1    1550 3300
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J3
U 1 1 5DFC1692
P 1550 3650
F 0 "J3" H 1578 3676 50  0000 L CNN
F 1 "Conn_01x01_Female" H 1578 3585 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x01_P2.54mm_Vertical" H 1550 3650 50  0001 C CNN
F 3 "~" H 1550 3650 50  0001 C CNN
	1    1550 3650
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0121
U 1 1 5DFC2652
P 1350 3300
F 0 "#PWR0121" H 1350 3150 50  0001 C CNN
F 1 "+5V" H 1365 3473 50  0000 C CNN
F 2 "" H 1350 3300 50  0001 C CNN
F 3 "" H 1350 3300 50  0001 C CNN
	1    1350 3300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0122
U 1 1 5DFC2C71
P 1350 3650
F 0 "#PWR0122" H 1350 3400 50  0001 C CNN
F 1 "GND" H 1355 3477 50  0000 C CNN
F 2 "" H 1350 3650 50  0001 C CNN
F 3 "" H 1350 3650 50  0001 C CNN
	1    1350 3650
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Female J4
U 1 1 5DFCAAD5
P 3300 3450
F 0 "J4" H 3328 3476 50  0000 L CNN
F 1 "Conn_01x03_Female" H 3328 3385 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 3300 3450 50  0001 C CNN
F 3 "~" H 3300 3450 50  0001 C CNN
	1    3300 3450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0123
U 1 1 5DFCBA20
P 3100 3350
F 0 "#PWR0123" H 3100 3100 50  0001 C CNN
F 1 "GND" V 3105 3222 50  0000 R CNN
F 2 "" H 3100 3350 50  0001 C CNN
F 3 "" H 3100 3350 50  0001 C CNN
	1    3100 3350
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR0125
U 1 1 5DFCC754
P 3100 3550
F 0 "#PWR0125" H 3100 3400 50  0001 C CNN
F 1 "+5V" V 3115 3678 50  0000 L CNN
F 2 "" H 3100 3550 50  0001 C CNN
F 3 "" H 3100 3550 50  0001 C CNN
	1    3100 3550
	0    -1   -1   0   
$EndComp
Text GLabel 5900 3050 2    50   Input ~ 0
PA13
Text GLabel 5900 3150 2    50   Input ~ 0
PA14
$Comp
L Connector:Conn_01x04_Female J5
U 1 1 5DFE2A5D
P 7650 3150
F 0 "J5" H 7678 3126 50  0000 L CNN
F 1 "Conn_01x04_Female" H 7678 3035 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 7650 3150 50  0001 C CNN
F 3 "~" H 7650 3150 50  0001 C CNN
	1    7650 3150
	1    0    0    -1  
$EndComp
Text GLabel 7450 3150 0    50   Input ~ 0
PA13
Text GLabel 7450 3250 0    50   Input ~ 0
PA14
Text GLabel 7450 3350 0    50   Input ~ 0
NRST
Text GLabel 6000 2550 2    50   Input ~ 0
PA8
Text GLabel 6000 2650 2    50   Input ~ 0
PA9
Wire Wire Line
	6000 2550 5900 2550
Wire Wire Line
	6000 2650 5900 2650
$Comp
L Connector:Conn_01x04_Female J8
U 1 1 5E009AB9
P 10050 2550
F 0 "J8" H 10078 2526 50  0000 L CNN
F 1 "Conn_01x04_Female" H 10078 2435 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 10050 2550 50  0001 C CNN
F 3 "~" H 10050 2550 50  0001 C CNN
	1    10050 2550
	1    0    0    -1  
$EndComp
Text GLabel 9150 2550 0    50   Input ~ 0
PA9
Text GLabel 9150 2450 0    50   Input ~ 0
PA8
$Comp
L power:GND #PWR0128
U 1 1 5E00C01D
P 9850 2750
F 0 "#PWR0128" H 9850 2500 50  0001 C CNN
F 1 "GND" H 9855 2577 50  0000 C CNN
F 2 "" H 9850 2750 50  0001 C CNN
F 3 "" H 9850 2750 50  0001 C CNN
	1    9850 2750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0129
U 1 1 5E00C8A5
P 9850 2650
F 0 "#PWR0129" H 9850 2400 50  0001 C CNN
F 1 "GND" V 9855 2522 50  0000 R CNN
F 2 "" H 9850 2650 50  0001 C CNN
F 3 "" H 9850 2650 50  0001 C CNN
	1    9850 2650
	0    1    1    0   
$EndComp
$Comp
L Device:C C8
U 1 1 5E0140C6
P 9450 2450
F 0 "C8" V 9198 2450 50  0000 C CNN
F 1 "C" V 9289 2450 50  0000 C CNN
F 2 "Capacitor_THT:C_Axial_L3.8mm_D2.6mm_P7.50mm_Horizontal" H 9488 2300 50  0001 C CNN
F 3 "~" H 9450 2450 50  0001 C CNN
	1    9450 2450
	0    1    1    0   
$EndComp
$Comp
L Device:C C7
U 1 1 5E014A79
P 9350 2750
F 0 "C7" V 9098 2750 50  0000 C CNN
F 1 "C" V 9189 2750 50  0000 C CNN
F 2 "Capacitor_THT:C_Axial_L3.8mm_D2.6mm_P7.50mm_Horizontal" H 9388 2600 50  0001 C CNN
F 3 "~" H 9350 2750 50  0001 C CNN
	1    9350 2750
	0    1    1    0   
$EndComp
Wire Wire Line
	9150 2450 9300 2450
Wire Wire Line
	9600 2450 9850 2450
Wire Wire Line
	9850 2550 9500 2550
Wire Wire Line
	9500 2550 9500 2750
Wire Wire Line
	9200 2750 9200 2550
Wire Wire Line
	9200 2550 9150 2550
$Comp
L Connector:Conn_01x01_Female J6
U 1 1 5E0226F1
P 7450 3550
F 0 "J6" H 7478 3576 50  0000 L CNN
F 1 "Conn_01x01_Female" H 7478 3485 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x01_P2.54mm_Vertical" H 7450 3550 50  0001 C CNN
F 3 "~" H 7450 3550 50  0001 C CNN
	1    7450 3550
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0130
U 1 1 5E02386D
P 7250 3550
F 0 "#PWR0130" H 7250 3400 50  0001 C CNN
F 1 "+5V" H 7265 3723 50  0000 C CNN
F 2 "" H 7250 3550 50  0001 C CNN
F 3 "" H 7250 3550 50  0001 C CNN
	1    7250 3550
	-1   0    0    1   
$EndComp
NoConn ~ 4700 2550
NoConn ~ 4700 2650
NoConn ~ 4700 2750
NoConn ~ 4700 2850
NoConn ~ 4700 2950
NoConn ~ 4700 3050
NoConn ~ 4700 3250
NoConn ~ 4700 3450
NoConn ~ 4700 3550
NoConn ~ 4700 3650
NoConn ~ 4700 3750
NoConn ~ 4700 3850
NoConn ~ 4700 3950
NoConn ~ 4700 4050
NoConn ~ 4700 4150
NoConn ~ 4700 4250
NoConn ~ 4700 4350
NoConn ~ 4700 4450
NoConn ~ 4700 4550
NoConn ~ 4700 4650
NoConn ~ 4700 4750
NoConn ~ 4700 4850
NoConn ~ 4700 4950
NoConn ~ 5900 2750
NoConn ~ 5900 2850
NoConn ~ 5900 2950
NoConn ~ 5900 3250
NoConn ~ 5900 4850
NoConn ~ 5900 4950
NoConn ~ 1800 5100
$Comp
L Connector:Conn_01x04_Female J9
U 1 1 5E092214
P 6300 1950
F 0 "J9" H 6328 1926 50  0000 L CNN
F 1 "Conn_01x04_Female" H 6328 1835 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 6300 1950 50  0001 C CNN
F 3 "~" H 6300 1950 50  0001 C CNN
	1    6300 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 1850 6100 1850
Wire Wire Line
	5900 1950 6100 1950
Wire Wire Line
	5900 2050 6100 2050
Wire Wire Line
	5900 2150 6100 2150
NoConn ~ 5900 1750
NoConn ~ 5900 2250
$Comp
L power:GND #PWR0131
U 1 1 5E0A4398
P 7450 3050
F 0 "#PWR0131" H 7450 2800 50  0001 C CNN
F 1 "GND" V 7455 2922 50  0000 R CNN
F 2 "" H 7450 3050 50  0001 C CNN
F 3 "" H 7450 3050 50  0001 C CNN
	1    7450 3050
	0    1    1    0   
$EndComp
Wire Wire Line
	9350 1400 9350 1200
Wire Wire Line
	9350 1200 9000 1200
Wire Wire Line
	9000 1050 9000 1200
Connection ~ 9000 1200
Wire Wire Line
	9350 1700 9350 1900
Wire Wire Line
	7600 1050 7600 1150
Wire Wire Line
	7950 1300 7950 1150
Wire Wire Line
	7950 1150 7600 1150
Connection ~ 7600 1150
Wire Wire Line
	7600 1150 7600 1250
Text GLabel 5350 1300 1    50   Input ~ 0
VDD
Wire Wire Line
	5200 1550 5200 1400
Wire Wire Line
	5200 1400 5300 1400
Wire Wire Line
	5350 1400 5350 1300
Wire Wire Line
	5300 1550 5300 1400
Connection ~ 5300 1400
Wire Wire Line
	5300 1400 5350 1400
Wire Wire Line
	5350 1400 5400 1400
Wire Wire Line
	5500 1400 5500 1550
Connection ~ 5350 1400
Wire Wire Line
	5400 1550 5400 1400
Connection ~ 5400 1400
Wire Wire Line
	5400 1400 5500 1400
Text GLabel 5650 750  0    50   Input ~ 0
VDD
Wire Wire Line
	5850 750  5650 750 
Wire Wire Line
	3100 5500 3100 5700
Text GLabel 3100 5500 1    50   Input ~ 0
VDD
Text GLabel 7600 700  1    50   Input ~ 0
VDD
Wire Wire Line
	7600 700  7600 750 
Text GLabel 9000 750  1    50   Input ~ 0
VDD
Text GLabel 2800 3450 0    50   Input ~ 0
VDD
Wire Wire Line
	2800 3450 3100 3450
Text GLabel 2500 1250 2    50   Input ~ 0
VDD
Wire Wire Line
	2250 1250 2500 1250
$Comp
L power:+3.3V #PWR0104
U 1 1 5E196B3C
P 5850 750
F 0 "#PWR0104" H 5850 600 50  0001 C CNN
F 1 "+3.3V" H 5865 923 50  0000 C CNN
F 2 "" H 5850 750 50  0001 C CNN
F 3 "" H 5850 750 50  0001 C CNN
	1    5850 750 
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0119
U 1 1 5E12B300
P 1800 4700
F 0 "#PWR0119" H 1800 4550 50  0001 C CNN
F 1 "+5V" H 1815 4873 50  0000 C CNN
F 2 "" H 1800 4700 50  0001 C CNN
F 3 "" H 1800 4700 50  0001 C CNN
	1    1800 4700
	1    0    0    -1  
$EndComp
$Comp
L Connector:USB_B_Micro J1
U 1 1 5DFB7597
P 1500 4900
F 0 "J1" H 1557 5367 50  0000 C CNN
F 1 "USB_B_Micro" H 1557 5276 50  0000 C CNN
F 2 "Connector_USB:USB_Micro-B_Molex_47346-0001" H 1650 4850 50  0001 C CNN
F 3 "~" H 1650 4850 50  0001 C CNN
	1    1500 4900
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5E1A0A4B
P 6800 900
F 0 "#FLG0101" H 6800 975 50  0001 C CNN
F 1 "PWR_FLAG" H 6800 1073 50  0000 C CNN
F 2 "" H 6800 900 50  0001 C CNN
F 3 "~" H 6800 900 50  0001 C CNN
	1    6800 900 
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0105
U 1 1 5E1A106F
P 6800 900
F 0 "#PWR0105" H 6800 750 50  0001 C CNN
F 1 "+3.3V" H 6815 1073 50  0000 C CNN
F 2 "" H 6800 900 50  0001 C CNN
F 3 "" H 6800 900 50  0001 C CNN
	1    6800 900 
	-1   0    0    1   
$EndComp
$EndSCHEMATC