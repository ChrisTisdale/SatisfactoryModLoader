// This file has been automatically generated by the Unreal Header Implementation tool

#include "Buildables/FGBuildableRailroadTrack.h"
#include "Components/SceneComponent.h"
#include "Components/SplineComponent.h"
#include "FGRailroadTrackConnectionComponent.h"
#include "Hologram/FGRailroadTrackHologram.h"
#include "InstancedSplineMeshComponent.h"

bool FRailroadTrackPosition::Serialize(FArchive& ar) {
	if (ar.ArIsSaveGame) {
		ar << Offset;
		ar << Forward;
	}

	return true;
}

FRailroadTrackPosition::FRailroadTrackPosition(){ }
FRailroadTrackPosition::FRailroadTrackPosition( AFGBuildableRailroadTrack* track, float offset, float forward){ }
FRailroadTrackPosition::FRailroadTrackPosition(const FRailroadTrackPosition& position){ }
FRailroadTrackPosition::~FRailroadTrackPosition(){ }
void FRailroadTrackPosition::GetWorldLocationAndDirection(FVector& out_location, FVector& out_direction) const{ }
float FRailroadTrackPosition::GetForwardOffset() const{ return float(); }
float FRailroadTrackPosition::GetReverseOffset() const{ return float(); }
UFGRailroadTrackConnectionComponent* FRailroadTrackPosition::GetForwardConnection() const{ return nullptr; }
UFGRailroadTrackConnectionComponent* FRailroadTrackPosition::GetReverseConnection() const{ return nullptr; }
AFGBuildableRailroadTrack* FRailroadTrackPosition::GetForwardTrack() const{ return nullptr; }
AFGBuildableRailroadTrack* FRailroadTrackPosition::GetReverseTrack() const{ return nullptr; }
const FRailroadTrackPosition FRailroadTrackPosition::InvalidTrackPosition = FRailroadTrackPosition();
AFGBuildableRailroadTrack::AFGBuildableRailroadTrack() : Super() {
	this->mMesh = nullptr;
	this->mMeshLength = 0.0;
	this->mSplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
	this->mInstancedSplineMesh = CreateDefaultSubobject<UInstancedSplineMeshComponent>(TEXT("InstancedSplineMesh"));
	this->mConnections.Add(CreateDefaultSubobject<UFGRailroadTrackConnectionComponent>(TEXT("TrackConnection0")));
	this->mConnections.Add(CreateDefaultSubobject<UFGRailroadTrackConnectionComponent>(TEXT("TrackConnection1")));
	this->mIsOwnedByPlatform = false;
	this->mTrackGraphID = -1;
	this->mBlockVisualizationMesh = nullptr;
	this->mHologramClass = AFGRailroadTrackHologram::StaticClass();
	this->mSplineComponent->SetupAttachment(RootComponent);
	this->mInstancedSplineMesh->SetupAttachment(RootComponent);
	this->mConnections[0]->SetupAttachment(RootComponent);
	this->mConnections[1]->SetupAttachment(RootComponent);
}
void AFGBuildableRailroadTrack::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFGBuildableRailroadTrack, mSplineData);
	DOREPLIFETIME(AFGBuildableRailroadTrack, mSignalBlockID);
}
void AFGBuildableRailroadTrack::BeginPlay(){ }
void AFGBuildableRailroadTrack::Destroyed(){ }
void AFGBuildableRailroadTrack::Dismantle_Implementation(){ }
bool AFGBuildableRailroadTrack::CanDismantle_Implementation() const{ return bool(); }
void AFGBuildableRailroadTrack::PostLoadGame_Implementation(int32 saveVersion, int32 gameVersion){ }
int32 AFGBuildableRailroadTrack::GetDismantleRefundReturnsMultiplier() const{ return int32(); }
void AFGBuildableRailroadTrack::ShowBlockVisualization(){ }
void AFGBuildableRailroadTrack::StopBlockVisualization(){ }
FRailroadTrackPosition AFGBuildableRailroadTrack::FindTrackPositionClosestToWorldLocation(const FVector& worldLocation){ return FRailroadTrackPosition(); }
void AFGBuildableRailroadTrack::GetWorldLocationAndDirectionAtPosition(const  FRailroadTrackPosition& position, FVector& out_location, FVector& out_direction) const{ }
UFGPowerConnectionComponent* AFGBuildableRailroadTrack::GetThirdRail() const{ return nullptr; }
void AFGBuildableRailroadTrack::OnVehicleEntered( AFGRailroadVehicle* vehicle){ }
void AFGBuildableRailroadTrack::OnVehicleExited( AFGRailroadVehicle* vehicle){ }
bool AFGBuildableRailroadTrack::IsConnectionOccupied(const  UFGRailroadTrackConnectionComponent* connection, float distance) const{ return bool(); }
bool AFGBuildableRailroadTrack::UpdateOverlappingTracks(){ return bool(); }
TArray< AFGBuildableRailroadTrack* > AFGBuildableRailroadTrack::GetOverlappingTracks(){ return TArray<AFGBuildableRailroadTrack*>(); }
void AFGBuildableRailroadTrack::AddOverlappingTrack(AFGBuildableRailroadTrack* track){ }
void AFGBuildableRailroadTrack::SetupConnections(){ }
void AFGBuildableRailroadTrack::PostSerializedFromBlueprint(bool isBlueprintWorld){ }
void AFGBuildableRailroadTrack::UnrotateForBlueprintPlaced(){ }
void AFGBuildableRailroadTrack::SetTrackGraphID(int32 trackGraphID){ }
void AFGBuildableRailroadTrack::SetSignalBlock(TWeakPtr< FFGRailroadSignalBlock > block){ }
void AFGBuildableRailroadTrack::OnRep_SignalBlockID(){ }
