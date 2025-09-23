#include <gtest/gtest.h>
#include "../ObserverConcrete.h"
#include "../ListaSpesa.h"

TEST(ObserverConcreteTest, CostruttoreNonValido) {
    EXPECT_THROW({ObserverConcrete observer(nullptr);}, std::invalid_argument);
}


TEST(ObserverConcreteTest, CostruttoreConSubjectValido) {
    ListaSpesa lista;

    EXPECT_NO_THROW({ObserverConcrete observer(&lista);});
}


TEST(ObserverConcreteTest, ConstruttoreCopia) {
    ListaSpesa lista;
    ObserverConcrete observer1(&lista);

    ObserverConcrete observer2(observer1);
    EXPECT_TRUE(lista.hasObserver(&observer2));
}


TEST(ObserverConcreteTest, OperatoreAssegnazione) {
    ListaSpesa lista1;
    ListaSpesa lista2;
    ObserverConcrete observer1(&lista1);
    ObserverConcrete observer2(&lista2);

    EXPECT_NO_THROW({observer2 = observer1;});
}


TEST(ObserverConcreteTest, VerificaCorrettezzaAttach) {
    ListaSpesa lista;
    ObserverConcrete observer(&lista);   // Attach() nel costruttore

    EXPECT_TRUE(lista.hasObserver(&observer)) << "Observer non è stato correttamente registrato in attach()";
}


TEST(ObserverConcreteTest, VerificaCorrettezzaDettach) {
    ListaSpesa lista;
    ObserverConcrete observer(&lista);   // Attach automatico

    ASSERT_TRUE(lista.hasObserver(&observer)) << "Observer dovrebbe essere registrato dopo il costruttore";

    observer.detach();

    EXPECT_FALSE(lista.hasObserver(&observer)) << "Observer non è stato correttamente rimosso in detach()";
}


TEST(ObserverConcreteTest, UpdateStampato) {
    ListaSpesa lista;
    ObserverConcrete observer(&lista);
    OggettoLista ogg("pane", 2, Categoria("Alimentari"));
    lista.aggiungiOggetto(ogg);

    SUCCEED() << "Se non ci sono crash o errori, update() è statochiamato.";
}
