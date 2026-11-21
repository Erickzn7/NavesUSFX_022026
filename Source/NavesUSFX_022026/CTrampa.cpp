// CTrampa.cpp
#include "CTrampa.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"

ACTrampa::ACTrampa()
{
    TipoComponente      = ETipoComponente::Trampa;
    Resistencia         = 50.0f;
    DanoAlActivar       = 25.0f;
    IntervaloActivacion = 2.0f;
    bActivada           = false;

    // Cubo pequeno y bajo
    Malla->SetRelativeScale3D(FVector(2.0f, 2.0f, 0.15f));
}

void ACTrampa::BeginPlay()
{
    Super::BeginPlay();

    // Comienza a pulsar cada IntervaloActivacion segundos
    GetWorldTimerManager().SetTimer(
        TimerActivacion, this, &ACTrampa::Activar,
        IntervaloActivacion, true);

    ComportamientoIndividual();
}

void ACTrampa::ComportamientoIndividual()
{
    UE_LOG(LogTemp, Log,
        TEXT("[Trampa #%d] Armada — Dano: %.0f, Intervalo: %.1fs"),
        NumeroComponente, DanoAlActivar, IntervaloActivacion);
}

void ACTrampa::ComportamientoGrupo(int32 TotalComponentes)
{
    // En grupo: el intervalo se acorta (trampas mas rapidas)
    IntervaloActivacion = FMath::Max(0.5f, IntervaloActivacion - TotalComponentes * 0.1f);

    // Reiniciar timer con nuevo intervalo
    GetWorldTimerManager().ClearTimer(TimerActivacion);
    GetWorldTimerManager().SetTimer(
        TimerActivacion, this, &ACTrampa::Activar,
        IntervaloActivacion, true);

    UE_LOG(LogTemp, Log,
        TEXT("[Trampa #%d] Grupo: Intervalo reducido a %.2fs (grupo de %d)"),
        NumeroComponente, IntervaloActivacion, TotalComponentes);
}

void ACTrampa::Activar()
{
    if (!bActivo) return;
    bActivada = true;

    UE_LOG(LogTemp, Warning,
        TEXT("[Trampa #%d] ACTIVADA — inflige %.0f de dano"),
        NumeroComponente, DanoAlActivar);

    // Desactivar tras 0.5s
    GetWorldTimerManager().SetTimer(
        TimerActivacion, this, &ACTrampa::Desactivar, 0.5f, false);
}

void ACTrampa::Desactivar()
{
    bActivada = false;
    UE_LOG(LogTemp, Log,
        TEXT("[Trampa #%d] desactivada"), NumeroComponente);

    // Reiniciar ciclo
    GetWorldTimerManager().SetTimer(
        TimerActivacion, this, &ACTrampa::Activar,
        IntervaloActivacion, false);
}
