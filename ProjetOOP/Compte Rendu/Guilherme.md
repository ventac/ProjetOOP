# Compte rendu
## ...
- Wrote the basic program, already with the animated road (but in the wrong direction).

## Friday, November 29, 2024
- Wrote the documentation to show the teacher.
- Configured SDL in Xcode.

## Tuesday, December 11, 2024
- Created this document to take notes of progress.
- Rewrote the documentation in MD format to improve readability.
- Decided to use VS Code instead of Xcode because it was not working properly on Jarod's PC.
- Thanks to Jarod and the teacher, the project works in Visual Studio Code and it will be the IDE we will use for now on.

## Monday, January 6, 2025
- Made changes to README.md, adding new install instructions.
- Added GitHub badges.
- Created "create-player-car" branch.
- Created PlayerCar.h and PlayerCar.cpp
- Created Road.h and Road.cpp for proper handling of its rendering.

## Wed, February 6, 2025
1. **Road Movement Adjustment**:
   - Moved the `Y` position of the road to public access and changed its value directly in the `main` function. This allows the road to stop without halting the renderer.

2. **Game Over Keystroke Detection**:
   - Modified the key detection during the Game Over screen to allow waiting for the player to press "r" to restart or "q" to quit the game. Now the keystrokes are detected properly.

3. **NPC Car1 Reintroduced**:
   - Re-added `NPC car1` because the game was too easy without it. This helps improve the game's difficulty.

4. **Removed Unnecessary Comments**:
   - Cleaned up the code by removing unnecessary comments. This helps to improve code readability and maintainability.

5. **Overloaded `checkCollision` Function**:
   - Created an overloaded version of the `checkCollision` function specifically for NPC usage. Now, when an NPC collides with the player, it gets relocated to the right side of the screen, adding a more realistic behavior.

6. **Translation of Comments**:
   - Translated all comments from French to English for consistency and clarity.

7. **Game Over Image**:
   - Added a `Game Over` image to the screen. The image is now centered dynamically based on the screen size.

8. **Randomized NPC Start Position**:
   - Changed the starting `Y` position of the NPC cars to be randomized. Previously, the cars only started at different `X` positions. Now, they start at various random `Y` positions, making the game feel more natural and varied.

9. **Fixed NPC Positioning**:
   - Fixed the issue where sometimes NPCs appeared in the middle of the screen, ensuring that the NPCs now appear at the correct positions.

10. **Random Offset for NPC Generation**:
    - Added a random offset between `-2` and `2` to the NPC generation. This introduces variation in their movement, making their behavior feel more random and less predictable.