#include<raylib.h>
#include<iostream>
int main(){
    // window dimensions
    const int windowWidth{512};
    const int windowHeight{380};

    // rectangle dimensions
    const int width{50};
    const int height{80};

    int posY{windowHeight-height};
    int velocity{0};

    // prevent air jumping
    bool isInAir{};
    // jump velocity
    const int jumpVel{-20};

    // acceleration due to gravity (pixels/frame)/frame
    const int gravity{1};

    SetTargetFPS(60);
    InitWindow(windowWidth,windowHeight,"Dasher");
    std::cout<<isInAir<<"\n";
    while(true){
        if(WindowShouldClose()){
            return false;
        }
        BeginDrawing();
        ClearBackground(WHITE);

        // Check for jumping
        if(IsKeyPressed(KEY_SPACE) && !isInAir){
            isInAir = true;  // Mark the object as in the air.
            std::cout<<isInAir<<"\n";
            velocity+=jumpVel;  // Set a negative velocity to move upward when the space key is pressed.
        }
        else{
            // Apply gravity
            velocity += gravity;  // Apply gravity to the velocity.
        }

        // Update position
        posY += velocity;  // Update the vertical position based on the current velocity.

        // Draw rectangle at the updated position
        DrawRectangle(windowWidth/2, posY, width, height, BLUE);

        // Check for collision with the ground
        if(posY >= windowHeight - height){
            posY = windowHeight - height;  // Snap the object to the ground.
            velocity = 0;  // Set the velocity to 0 when on the ground.
            isInAir = false;  // Mark the object as not in the air.
        }


        EndDrawing();
    }
    CloseWindow();
}