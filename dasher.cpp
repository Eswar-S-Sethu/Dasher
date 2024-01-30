#include<raylib.h>
#include<iostream>
int main(){
    // window dimensions
    const int windowWidth{512};
    const int windowHeight{380};

    int velocity{0};

    // prevent air jumping
    bool isInAir{};
    // jump velocity
    const int jumpVel{-700};

    // acceleration due to gravity (pixels/frame)/frame
    const int gravity{1500};

    SetTargetFPS(60); // this line and the next line goes first before loading any textures. only exception is variables
    InitWindow(windowWidth,windowHeight,"Dasher");

    // loading the textures and aligning it to the middle of the screen
    Texture2D scarfy=LoadTexture("C:/Users/GameDev/Documents/Dasher/textures/scarfy.png");
    Rectangle scarfyRec;
    scarfyRec.width=scarfy.width/6;
    scarfyRec.height=scarfy.height;
    scarfyRec.x=0;
    scarfyRec.y=0;
    Vector2 scarfyPos;
    scarfyPos.x=windowWidth/2-scarfyRec.width/2;
    scarfyPos.y=windowHeight-scarfyRec.height;

    while(true){
        if(WindowShouldClose()){
            return false;
        }
        // delta time  ( time since the last frame )
        const float dT{GetFrameTime()};

        BeginDrawing();
        ClearBackground(WHITE);

        // Check for jumping
        if(IsKeyPressed(KEY_SPACE) && !isInAir){
            isInAir = true;  // Mark the object as in the air.
            velocity+=jumpVel;  // Set a negative velocity to move upward when the space key is pressed.
        }
        else{
            // Apply gravity
            velocity += gravity*dT;  // Apply gravity to the velocity.
        }

        // Update position
        scarfyPos.y += velocity*dT;  // Update the vertical position based on the current velocity.

        // Draw rectangle at the updated position
        DrawTextureRec(scarfy,scarfyRec,scarfyPos,WHITE);

        // Check for collision with the ground
        if(scarfyPos.y >= windowHeight - scarfyRec.height){
            scarfyPos.y = windowHeight - scarfyRec.height;  // Snap the object to the ground.
            velocity = 0;  // Set the velocity to 0 when on the ground.
            isInAir = false;  // Mark the object as not in the air.
        }


        EndDrawing();
    }
    UnloadTexture(scarfy);
    CloseWindow();
}