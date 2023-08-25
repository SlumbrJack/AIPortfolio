// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FireGrenade.generated.h"

UCLASS()
class AIPORTFOLIO_API AFireGrenade : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFireGrenade();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	

	
	
	//capsule
	UPROPERTY(EditAnywhere)
	class UBoxComponent* BoxComponent;
	//inair mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* AirMesh;

	//ongroundMesh
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* GroundMesh;

	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
	bool isGrounded = false;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	TSubclassOf<class AFireField> FieldClass;

};
