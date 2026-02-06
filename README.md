# space-invaders
A simple recreation of Space Invaders, made in C++ using SFML 3.
Was challenged by Computer Science teacher to make it, and helped me famialirise myself with unique game mechanics.

## About this project
I was challenged by my Computer Science teacher to recreate a simple version of Space Invaders. Features a flying shit that can be controlled by the user via the the arrows keys, and pressing space shoots a bullet.
It was actually quite fun to make this. I implemented concepts like exponential deceleration which made the ship actually feel like it was in space, a points system, and audio.
Some challenges I faced:
- Memory allocation. I learnt how to properly manage the memory of limited-lifetime objects so that there wouldn't be any crashes.
- Audio. I learnt how it worked, what should be streamed or stored in memory, and how to make it play when I wanted it to.
- Gameplay. I learnt how to microadjust settings like the speeds of entities so that the gameplay always felt like you were on the brink of losing, but it was you keeping it together.


## Features
- A player-controllable character that can shoot projectiles.
- Oncoming swarm of aliens descending from the top.
- A points system to track how many aliens you killed.
- Music and SFX that play.

## Gallery
<img src="https://github.com/user-attachments/assets/a367b9d2-855c-4a96-a51c-701566beac77" width="320" />


## Build & Run
```bash
mkdir build && cd build
cmake ..
cmake --build . 
cd bin
./space-invaders
```

Requires SFML 3.0.2, C Make and C++17.

## Licence
Copyright © 2025 Jay Rickaby,
Licensed under the MIT License
