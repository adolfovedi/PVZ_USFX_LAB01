// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PVZ_USFX_LAB01Pawn.generated.h"

UCLASS(Blueprintable)
class APVZ_USFX_LAB01Pawn : public APawn
{
	GENERATED_BODY()

	/* The mesh component */
	// El componente de malla 
	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* ShipMeshComponent;

	/** The camera */
	// La c�mara 
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent;

	/** Camera boom positioning the camera above the character */
	// Brazo de la c�mara posicionando la c�mara sobre el personaje 
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

public:
	APVZ_USFX_LAB01Pawn();

	/** Offset from the ships location to spawn projectiles */
	// Desplazamiento desde la ubicaci�n de la nave para generar proyectiles 
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite )
	FVector GunOffset;
	
	/* How fast the weapon will fire */
	// La velocidad a la que el arma disparar� 
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float FireRate;

	/* The speed our ship moves around the level */
	//La velocidad a la que nuestra nave se mueve por el nivel 
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float MoveSpeed;

	/** Sound to play each time we fire */
	// Sonido para reproducir cada vez que dispararnos 
	UPROPERTY(Category = Audio, EditAnywhere, BlueprintReadWrite)
	class USoundBase* FireSound;

	// Begin Actor Interface
	// Comienzo de la Interfaz del Actor

	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End Actor Interface
	// Fin de la Interfaz del Actor


	/* Fire a shot in the specified direction */
	// Disparar un proyectil en la direcci�n especificada 

	void FireShot(FVector FireDirection);

	/* Handler for the fire timer expiry */
	// Manejador para la expiraci�n del temporizador de disparo 

	void ShotTimerExpired();

	// Static names for axis bindings
	// Nombres est�ticos para asignaciones de ejes
	static const FName MoveForwardBinding;
	static const FName MoveRightBinding;
	static const FName FireForwardBinding;
	static const FName FireRightBinding;

private:

	/* Flag to control firing  */
	// Bandera para controlar el disparo 

	uint32 bCanFire : 1;

	/** Handle for efficient management of ShotTimerExpired timer */
	// Manejador para una gesti�n eficiente del temporizador ShotTimerExpired 

	FTimerHandle TimerHandle_ShotTimerExpired;

public:
	/** Returns ShipMeshComponent subobject **/
	// Devuelve el subobjeto ShipMeshComponent 

	FORCEINLINE class UStaticMeshComponent* GetShipMeshComponent() const { return ShipMeshComponent; }
	/** Returns CameraComponent subobject **/
	// Devuelve el subobjeto CameraComponent 

	FORCEINLINE class UCameraComponent* GetCameraComponent() const { return CameraComponent; }
	/** Returns CameraBoom subobject **/
	// Devuelve el subobjeto CameraBoom 
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
};







