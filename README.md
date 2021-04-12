PinchGlove—Physically detect pinch on the Oculus Quest
======================================================

The PinchGlove is an inut device for the Oculus Quest 2. Used alongside the hand tracking of the headset, the glove detect a pinch of the index or the middle finger based on an unambiguous electric contact rather than image detection.

## Motivation

This glove is inspired from the [OMG-VR gloves](https://arxiv.org/abs/1901.03532). These gloves were developped for Vive trackers and allow to track the position of the hand and to detect pinches ("mudra" poses); all in the lighest package possible. The OMG-VR gloves depend on the SteamVR lighthouses and are not compatible with the inceasigly popular Oculus Quest 2 headset.

The PinchGlove attempts to achieve the same thing for the Quest. The Quest has a hand tracking feature and can detect pinches using computer vision. This detection, however, can be confused with "near-contacts", occlusion, or when the hand is out of view. The glove is tracked using the hand-tracking feature of the headset but detects the pinches using an electrical contact that is unambiguous.

To interface with the VR headset, the glove presents itself as a bluetooth gamepad. Making a pinch emulate a button press.

## In this repository

This repository contains a description of the glove and instructions to build it, the code for the firmware, and a minimal "game" to demonstrate the functionality of the glove.

## Building the glove

The "brain" of the glove is an ESP32 microcontroller with bluetooth functionality. For this specific build, I used a TinyPICO development board that exposes all the microcontroller's pins, allows to program the chip and communicate with UART via USB, and has the circuitery to charge a LiPo battery. Because I wanted to use the board for other applications, I soldered female header pins to a protoboard that was sawed to the glove using regular thread; the board could be sawed to the glove directly which would remove most of the bulkyness.

I used a pool glove with 3 fingers to match the aesthetics of the OMG-VR glove. Any glove would work.

The fingers are connected to the board using conductive fabric and conductive thread. A strip of adhesive conductive frabric goes from the tip of each finger to the back of the hand, next to the board. Conductive thread then goed though the conductive fabric and in holes of the board. The thumb is connected to ground, the index is connected to pin 25, and the middle finger is connected to pin 21.

I wear a second glove on top of the first one. That second glove covers the electronics that would otherwise have an adverse effet on the hand tracking. It also maintain the battery in place. The tips of the second glove are cut so the conductive fabric is exposed.

## Building the firmware

## Running the demo

