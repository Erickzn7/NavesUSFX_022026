// CPared.cpp
#include "CPared.h"
#include "UObject/ConstructorHelpers.h"

ACPared::ACPared()
{
    TipoComponente   = ETipoComponente::Pared;
    Resistencia      = 300.0f;
    bEsDestructible  = true;

    // Cubo vertical como pared
    Malla->SetRelativeScale3D(FVector(0.3f, 4.0f, 3.0f));
}

void ACPared::ComportamientoIndividual()
{
    UE_LOG(LogTemp, Log,
        TEXT("[Pared #%d] Pared lista — Destructible: %s, Resistencia: %.0f"),
        NumeroComponente,
        bEsDestructible ? TEXT("SI") : TEXT("NO"),
        Resistencia);
}

void ACPared::ComportamientoGrupo(int32 TotalComponentes)
{
    // En grupo: las paredes forman un muro reforzado
    Resistencia *= 1.5f;
    UE_LOG(LogTemp, Log,
        TEXT("[Pared #%d] Grupo: Resistencia reforzada a %.0f (grupo de %d)"),
        NumeroComponente, Resistencia, TotalComponentes);
}

void ACPared::RecibirDano(float Cantidad)
{
    if (!bEsDestructible || !bActivo) return;

    Resistencia -= Cantidad;
    UE_LOG(LogTemp, Warning,
        TEXT("[Pared #%d] Recibio dano %.0f — Resistencia restante: %.0f"),
        NumeroComponente, Cantidad, Resistencia);

    if (Resistencia <= 0.0f)
    {
        bActivo = false;
        UE_LOG(LogTemp, Warning,
            TEXT("[Pared #%d] DESTRUIDA"), NumeroComponente);
        Destroy();
    }
}
