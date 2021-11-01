# An external cheat for Far Cry 4 (Uplay), written in C++.

## Installation

1. Clone the repository with: `git clone --recursive https://github.com/cragson/far-cry-4-external.git`
2. Open the **.sln** file with Visual Studio 2019 and compile the solution
  - **Make sure to compile in x64 Release mode for full optimization**

## How to use
1. Start the compiled cheat **far-cry-4-external.exe** with administrator rights
2. Start the game via Uplay, doesn't matter if Uplay was running before or not
3. Wait for the cheat to prepare, will print offsets and features to the console when it's ready
4. Have **fun**

## Features
- Infinite Ammo
- Infinite Throwables
- Free Vendor
  1. You still need to have the required money to buy things from a vendor but no money will be subtracted or added to your wallet
  2. Make sure to turn off before selling, otherwise you will not earn any money
- Infinite Stimpacks
- God Mode
- Unlock all buyables
- Infinite Backpack
- Norecoil
- Cali Mode

## Known bugs
- God Mode
  1. You can still die if an animal knocks you to the ground
  2. Some story missions may be unplayable with enabled god mode, because you don't die from fall damage and reach invalid areas of the map
  3. Everything which is an instant kill in the game will still kill you, so be prepared

- Norecoil
  1. This feature is quite experimental because of my implementation
  2. In my opinion, I override the Y-axis of the players viewport. So you will still have minimal (0.010f) recoil on the Y-Axis but with full auto guns it's almost not noticeable
  3. Don't use a MG on a bipod with enabled norecoil, just don't.

- Cali Mode
  1. Well if you wanna be cali, be prepared to restart the game if cali fucks up your view. 
