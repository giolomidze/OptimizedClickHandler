#include <iostream>
#include <thread>
#include <Windows.h>
#include <chrono>
#include <ctime>

// Global variable to store the current state of the mouse clicking
bool clicking = false;

// Global variable to store the current listening state
bool listening = false;

// Function to simulate mouse clicking
void simulateMouseClick()
{
    // Simulate a left mouse click
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

// Function to detect key presses
// Returns true if the specified key is pressed, false otherwise
bool isKeyPressed(int keyCode)
{
    return (GetKeyState(keyCode) & 0x8000) != 0;
}

// Helper function to check if the mouse clicking should be enabled
bool shouldEnableMouseClicking()
{
    return listening && isKeyPressed(0x38);
}

// Helper function to check if the mouse clicking should be disabled
bool shouldDisableMouseClicking()
{
    return listening && isKeyPressed(0x39);
}

void updateMouseClickingState()
{
    // Add a flag to keep track of whether a message has been output or not
    static bool messageOutput = false;

    // Check if the number 1 key is pressed
    if (isKeyPressed(0x31))
    {
        // Enable listening to number 8 and number 9 keys
        listening = true;

        // Only output the message if one hasn't been output yet
        if (!messageOutput)
        {
            std::time_t timestamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            std::cout << "Listening enabled at " << std::ctime(&timestamp);
            messageOutput = true;
        }
    }

    // Check if the number 0 key is pressed
    if (isKeyPressed(0x30))
    {
        // Stop listening to keyboard
        listening = false;

        // Only output the message if one hasn't been output yet
        if (!messageOutput)
        {
            std::time_t timestamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            std::cout << "Listening disabled at " << std::ctime(&timestamp);
            messageOutput = true;
        }
    }

    // Check if the mouse clicking should be enabled
    if (shouldEnableMouseClicking())
    {
        // Enable mouse clicking
        clicking = true;

        // Only output the message if one hasn't been output yet
        if (!messageOutput)
        {
            std::time_t timestamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            std::cout << "Mouse clicking enabled at " << std::ctime(&timestamp);
            messageOutput = true;
        }
    }

    // Check if the mouse clicking should be disabled
    if (shouldDisableMouseClicking())
    {
        // Disable mouse clicking
        clicking = false;

        // Only output the message if one hasn't been output yet
        if (!messageOutput)
        {
            std::time_t timestamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            std::cout << "Mouse clicking disabled at " << std::ctime(&timestamp);
            messageOutput = true;
        }
    }

    // Reset the messageOutput flag if none of the conditions above are met
    if (!isKeyPressed(0x31) && !isKeyPressed(0x30) && !shouldEnableMouseClicking() && !shouldDisableMouseClicking())
    {
        messageOutput = false;
    }

    // Check if the mouse clicking is currently enabled
    if (clicking)
    {
        // Simulate a mouse click
        simulateMouseClick();
    }
}


int main()
{
    // Hide the console window
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    // Loop indefinitely to listen for keyboard input
    while (true)
    {
        try
        {
            // Update the mouse clicking state
            updateMouseClickingState();

            // Sleep for a short period of time to avoid excessive CPU usage
            Sleep(20);
        }
        catch (const std::exception& ex)
        {
            // Print the error message to the console
            std::cerr << "Error: " << ex.what() << std::endl;
        }
    }

    return 0;
}