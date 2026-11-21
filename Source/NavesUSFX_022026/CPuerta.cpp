// CPuerta.cpp
#include "CPuerta.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"

ACPuerta::ACPuerta()
{
    TipoComponente = ETipoComponente::Puerta;
    Resistencia    = 150.0f;
    bEstaAbierta   = false;
    TiempoCierre   = 3.0f;

    // Cubo delgado como puerta
    Malla->SetRelativeScale3D(FVector(0.2f, 2.0f, 2.5f));
}

void ACPuerta::BeginPlay()
{
    Super::BeginPlay();
    ComportamientoIndividual();
}

void ACPuerta::ComportamientoIndividual()
{
    UE_LOG(LogTemp, Log,
        TEXT("[Puerta #%d] Lista — Estado: %s, Cierre automatico: %.1fs"),
        NumeroComponente,
        bEstaAbierta ? TEXT("ABIERTA") : TEXT("CERRADA"),
        TiempoCierre);
}

void ACPuerta::ComportamientoGrupo(int32 TotalComponentes)
{
    // En grupo: todas las puertas se abren a la vez
    Abrir();
    UE_LOG(LogTemp, Log,
        TEXT("[Puerta #%d] Grupo: apertura sincronizada (grupo de %d puertas)"),
        NumeroComponente, TotalComponentes);
}

void ACPuerta::Abrir()
{
    bEstaAbierta = true;
    SetActorHiddenInGame(true);         // Visualmente desaparece al abrir
    SetActorEnableCollision(false);

    UE_LOG(LogTemp, Log, TEXT("[Puerta #%d] Abierta"), NumeroComponente);

    // Auto-cierre despues de TiempoCierre segundos
    GetWorldTimerManager().SetTimer(TimerCierre, this, &ACPuerta::Cerrar, TiempoCierre, false);
}

void ACPuerta::Cerrar()
{
    bEstaAbierta = false;
    SetActorHiddenInGame(false);
    SetActorEnableCollision(true);

    UE_LOG(LogTemp, Log, TEXT("[Puerta #%d] Cerrada"), NumeroComponente);
}
