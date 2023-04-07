#include <stdio.h>
#include <stdlib.h>

typedef struct agacDugumu {//Düðüm yapýsýný oluþturuyoruz
    int alinanDeger;
    struct agacDugumu* solKok;
    struct agacDugumu* sagKok;
} agacDugumu;

int toplamaFonk(agacDugumu* agacKoku) {//alt düðümlerinin deðerlerinin toplamýný hesaplayan fonksiyon
    if (agacKoku == NULL) {
        return 0;
    } else {
        return agacKoku->alinanDeger + toplamaFonk(agacKoku->solKok) + toplamaFonk(agacKoku->sagKok);
    }
}

int main() {
	
	printf("Bahar Urundiker,1220505018,KLU\n");
	// Kök düðüm ve sol,sað alt düðümler kullanýcýdan istenir
    agacDugumu* agacKoku = (agacDugumu*)malloc(sizeof(agacDugumu));
    
    printf("Kok dugumunun degerini giriniz\n ");
    
    scanf("%d", &(agacKoku->alinanDeger));
    

    agacKoku->solKok = (agacDugumu*)malloc(sizeof(agacDugumu));
    
    printf("Sol dugumun degerini giriniz\n ");
    
    scanf("%d", &(agacKoku->solKok->alinanDeger));
    
    agacKoku->solKok->solKok = NULL;
    
    agacKoku->solKok->sagKok = NULL;
    

    agacKoku->sagKok = (agacDugumu*)malloc(sizeof(agacDugumu));
    
    printf("Sag dugumun degerini giriniz\n ");
    
    scanf("%d", &(agacKoku->sagKok->alinanDeger));
    
    agacKoku->sagKok->solKok = NULL;
    
    agacKoku->sagKok->sagKok = NULL;
  //alt düðümlerinin toplamý ve kökün deðerinin toplamý oluþturulur
    int solKokToplami = toplamaFonk(agacKoku->solKok);
    
    int sagKokToplami = toplamaFonk(agacKoku->sagKok);
    
    int toplamDeger = agacKoku->alinanDeger + solKokToplami + sagKokToplami;

    if (toplamDeger == solKokToplami + sagKokToplami) {
    	
        printf("Kokun alt dugumleri toplami, kokun degerine esittir\n");
        
    } else {
    	
        printf("Kokun alt dugumleri toplami, kokun degerine esit degildir!!!\n");
        
    }

    return 0;
}
