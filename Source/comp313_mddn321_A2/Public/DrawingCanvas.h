// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Texture2D.h"
#include "Object.h"
#include "Components/SceneComponent.h"
#include "DrawingCanvas.generated.h"


UCLASS(Blueprintable, BlueprintType)
class COMP313_MDDN321_A2_API UDrawingCanvas : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
        UTexture2D* dynamicCanvas;
    UFUNCTION(BlueprintCallable, Category = DrawingTools)
        void InitializeCanvas(const int32 pixelsH, const int32 pixelsV);
    UFUNCTION(BlueprintCallable, Category = DrawingTools)
        void UpdateCanvas();
    UFUNCTION(BlueprintCallable, Category = DrawingTools)
        void ClearCanvas();
	UFUNCTION(BlueprintCallable, Category = DrawingTools)
        void InitializeDrawingTools(const int32 brushRadius);
    UFUNCTION(BlueprintCallable, Category = DrawingTools)
        void DrawDot(const int32 pixelCoordX, const int32 pixelCoordY);
    UDrawingCanvas();
    ~UDrawingCanvas();
private:
	// draw brush tool
	std::unique_ptr<uint8[]> canvasBrushMask;
    int radius;
    int brushBufferSize;
    // canvas
    std::unique_ptr<uint8[]> canvasPixelData;
    int canvasWidth;
    int canvasHeight;
    int bytesPerPixel;
    int bufferPitch;
    int bufferSize;
    std::unique_ptr<FUpdateTextureRegion2D> echoUpdateTextureRegion;
    void setPixelColor(uint8*& pointer, uint8 red, uint8 green, uint8 blue, uint8 alpha);
};