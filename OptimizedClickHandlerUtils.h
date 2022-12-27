#pragma once

#include "OptimizedClickHandler.h"

// Function to simulate mouse clicking
void simulateMouseClick();

// Function to detect key presses
// Returns true if the specified key is pressed, false otherwise
bool isKeyPressed(int keyCode);

// Helper function to check if the mouse clicking should be enabled
bool shouldEnableMouseClicking();

// Helper function to check if the mouse clicking should be disabled
bool shouldDisableMouseClicking();

// Function to update the mouse clicking state based on the current keyboard input
void updateMouseClickingState();
