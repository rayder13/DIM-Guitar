# Progress

## Pinout

Below is the proposed pinout for the DIM Guitar based on an Arduino Pro Micro. The board should have enough GPIO's to accommodate the project. Hoping to use the TX/RX pins for future features but we will see how that pans out. Pin 7 is designated Fret 6 for future proofing a fork into GH6 6 fret guitar retro fit.

![Image of Pro Micro Pinout](/images/pinout.jpg)

## Fretboard

- **September 15th 2020** Kailh switches arived today. Had to order a second lot directly from Kailh as the switches I originally ordered nearly 8 weeks ago from a reseller still haven't arrived. Turns out my pcb footprint for the switches is flipped horizontally. Not a huge deal as i can just flip the pcb given the only components are switches and the pcb is symmetrical vertically. Plus there are additions to come for the pcb so as long as i have a working prototype i can still progress.
- The switches appear to be too tall even though they are pretty much the shortest i could find. There isn't enough room below the pcb to mount them in the pcb so the fret buttons will have to be modified to get the extra internal travel needed.

![Image of Prototype fretboard pcb](/images/fret_proto_1.jpg)

- **August 20th 2020** PCB's arrived 4 days early. Happy with these as far as quality and accuracy goes.

![Image of Prototype fretboard pcb](/images/FRETBOARD_PCB_0.1.jpg)

- Prototype pcb done and ordered. The pcb will use Kailh Choc low profile switches instead of the oem rubber membrane keys. This should fix sloppy fret keys and allow for a better feel depending on your preferences with tactile, clicky and linear keys available in the low profile switches.
- Potential to add led's to each switch for either all on lighting while connected or having the fret light up when pressed.

## D-Pad

- **August 20th 2020** PCB's arrived 4 days early.
- Works way better than expected, though research says that the exposed copper contacts will likely corrode over time and become unreliable. Will have to look into carbon or ENIG as a better option. For now the prototype 100% works as expected with no problems.

![Image of Prototype dpad pcb](/images/DPAD_PCB_0.1.jpg)

- Prototype pcb done and ordered. Utilising the original rubber membrane pad given how little the keys get used.
- Swapping to mechanical keys might not be easy given the confinement of space.

## Strummer

- **September 15th 2020** Kailh switches turned up. I ordered a set of Kailh box dark yellow switches to test for the strummer. They have a cherry footprint but a much thicker stem than normal Cherry switches which i like. Using the same footprint however gives you the ability to chop and change between switches as desired. They are however around 1-2mm shorter than the OEM switches. Might need a hat to make sure the strum bar doesn't feel "loose".

![Image of Kailh box switch compared to OEM](/images/kailh_strummer.jpg)

- Prototype pcb in progress. Cherry MX Black version design done but i am waiting for the Kailh Chic low profile switches to show up to decide whether to use them, MX Cherry blacks or Alps keys.

![Image of Prototype Strummer pcb](/images/DIM_STRUMMER_FRONT.svg)

## Start/Star Power/Whammy

- Prototype pcb in progress. Will likely use Kailh Choc low profile switches as well.

![Image of Prototype Mid Board pcb](/images/DIM_MID_BOARD_FRONT.svg)

## Arduino Controller

- Full working prototype was made on an Arduino Leonardo board. ~~Custom board based on the ATMEGA34U2 mcu will be prototyped after all of the other pcb's are verified working as intended.~~ A full pin hookup guild will be added on full release for anyone who wants to use an existing ATMEGA34U2 board (Arduino pro micro etc) as main controller board.
- After a bit of consideration the controller board will be a carrier board for an Arduino Pro Micro footprint instead of a custom 34U2 board. This will keep the costs down and realistically for this project there's no point reinventing the wheel.
