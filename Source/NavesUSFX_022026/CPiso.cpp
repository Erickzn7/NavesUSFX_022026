// CPiso.cpp
#include "CPiso.h"
#include "UObject/ConstructorHelpers.h"

ACPiso::ACPiso()
{
    TipoComponente      = ETipoComponente::Piso;
    Resistencia         = 200.0f;
    bEsMovil            = false;
    VelocidadMovimiento = 150.0f;
    DireccionMovimiento = FVector(1.0f, 0.0f, 0.0f);

    // Cubo aplanado como piso
    Malla->SetRelativeScale3D(FVector(4.0f, 4.0f, 0.3f));
}

void ACPiso::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!bActivo || !bEsMovil) return;

    FVector Pos = GetActorLocation();
    Pos += DireccionMovimiento * VelocidadMovimiento * DeltaTime;

    // Rebotar entre -400 y 400 en X
    if (Pos.X > 400.0f || Pos.X < -400.0f)
    {
        DireccionMovimiento.X *= -1.0f;
    }
    SetActorLocation(Pos);
}

void ACPiso::ComportamientoIndividual()
{
    UE_LOG(LogTemp, Log,
        TEXT("[Piso #%d] Piso inicializado — Movil: %s, Resistencia: %.0f"),
        NumeroComponente,
        bEsMovil ? TEXT("SI") : TEXT("NO"),
        Resistencia);
}

void ACPiso::ComportamientoGrupo(int32 TotalComponentes)
{
    // En grupo: si hay muchos pisos, activar movimiento
    if (TotalComponentes > 2)
    {
        bEsMovil = true;
        UE_LOG(LogTemp, Log,
            TEXT("[Piso #%d] Grupo activado: modo movil (total pisos en grupo: %d)"),
            NumeroComponente, TotalComponentes);
    }
}
