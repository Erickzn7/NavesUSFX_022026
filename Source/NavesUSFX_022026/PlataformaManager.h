// PlataformaManager.h
// ============================================================
//  LAB 06 - FACTORY METHOD
//  Manager / Cliente — usa las fabricas para crear componentes
//  y los almacena en un TMap<int32, AComponentePlataforma*>
//  donde la clave es el NumeroComponente (unico).
// ============================================================

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ComponentePlataforma.h"
#include "FabricaComponentePlataforma.h"
#include "PlataformaManager.generated.h"

UCLASS()
class NAVESUSFX_022026_API APlataformaManager : public AActor
{
    GENERATED_BODY()

public:
    APlataformaManager();

protected:
    virtual void BeginPlay() override;

public:
    // ============================================================
    //  TMap principal: clave = NumeroComponente (unico), valor = puntero al actor
    // ============================================================
    UPROPERTY(VisibleAnywhere, Category = "Plataforma")
    TMap<int32, AComponentePlataforma*> Componentes;

    // Cuantos componentes de cada tipo se crean al inicio
    UPROPERTY(EditAnywhere, Category = "Plataforma|Config")
    int32 CantidadPisos;

    UPROPERTY(EditAnywhere, Category = "Plataforma|Config")
    int32 CantidadParedes;

    UPROPERTY(EditAnywhere, Category = "Plataforma|Config")
    int32 CantidadPuertas;

    UPROPERTY(EditAnywhere, Category = "Plataforma|Config")
    int32 CantidadTrampolines;

    UPROPERTY(EditAnywhere, Category = "Plataforma|Config")
    int32 CantidadTrampas;

    // Separacion entre componentes al spawnear
    UPROPERTY(EditAnywhere, Category = "Plataforma|Config")
    float Espaciado;

    // ============================================================
    //  API publica
    // ============================================================

    // Crea un componente del tipo indicado y lo agrega al TMap
    AComponentePlataforma* CrearComponente(ETipoComponente Tipo, FVector Posicion);

    // Busca un componente por su numero unico
    AComponentePlataforma* ObtenerComponente(int32 Numero) const;

    // Elimina un componente del TMap y del mundo
    void EliminarComponente(int32 Numero);

    // Aplica ComportamientoGrupo a todos los componentes de un tipo
    void EjecutarComportamientoGrupo(ETipoComponente Tipo);

    // Imprime en log todos los componentes registrados
    void ImprimirRegistro() const;

private:
    // Contador global para generar claves unicas
    int32 ContadorID;

    // Instancias de cada fabrica concreta (creadas en BeginPlay)
    UPROPERTY()
    TMap<ETipoComponente, UFabricaComponentePlataforma*> Fabricas;

    // Inicializa las fabricas concretas
    void InicializarFabricas();

    // Genera la plataforma inicial segun las cantidades configuradas
    void GenerarPlataformaInicial();
};
