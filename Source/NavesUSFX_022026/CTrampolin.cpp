// CTrampolin.cpp
#include "CTrampolin.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "UObject/ConstructorHelpers.h"

ACTrampolin::ACTrampolin()
{
    TipoComponente = ETipoComponente::Trampolin;
    Resistencia    = 500.0f;
    FuerzaImpulso  = 1200.0f;

    // Cubo bajo y ancho como trampolin
    Malla->SetRelativeScale3D(FVector(3.0f, 3.0f, 0.2f));
}

void ACTrampolin::ComportamientoIndividual()
{
    UE_LOG(LogTemp, Log,
        TEXT("[Trampolin #%d] Listo — Fuerza de impulso: %.0f"),
        NumeroComponente, FuerzaImpulso);
}

void ACTrampolin::ComportamientoGrupo(int32 TotalComponentes)
{
    // En grupo: aumenta la fuerza de cada trampolin
    FuerzaImpulso += TotalComponentes * 100.0f;
    UE_LOG(LogTemp, Log,
        TEXT("[Trampolin #%d] Grupo: Impulso aumentado a %.0f (grupo de %d)"),
        NumeroComponente, FuerzaImpulso, TotalComponentes);
}

void ACTrampolin::AplicarImpulso(AActor* Actor)
{
    if (!Actor || !bActivo) return;

    ACharacter* Personaje = Cast<ACharacter>(Actor);
    if (Personaje)
    {
        Personaje->GetCharacterMovement()->AddImpulse(
            FVector(0.0f, 0.0f, FuerzaImpulso), true);

        UE_LOG(LogTemp, Log,
            TEXT("[Trampolin #%d] Impulso aplicado a %s"),
            NumeroComponente, *Actor->GetName());
    }
}
