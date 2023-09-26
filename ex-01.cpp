#include <stdio.h>
#include <unistd.h> // Para a fun��o sleep()

int main(){
	for(;;) {
	    // Leia o estado do bot�o (HIGH ou LOW)
	    int estadoBotao = digitalRead(pinoBotao);
	
	    // Lidar com transi��es de estado
	    switch (estadoAtual) {
	        case LIGADO:
	            if (estadoBotao == DESLIGADO) {
	                // Bot�o solto, mude para o estado PROTEGIDO
	                estadoAtual = PROTEGIDO;
	            }
	            break;
	
	        case PROTEGIDO:
	        	sleep(10); // "Dorme" por 10 segundos
	            // 10 segundos se passaram, mude para o estado DESLIGADO
	            estadoAtual = DESLIGADO;
	            break;
	
	        case DESLIGADO:
	            if (estadoBotao == LIGADO) {
	                // Bot�o pressionado novamente, volte para o estado LIGADO
	                estadoAtual = LIGADO;
	            }
	            break;
	    }
	}
	return 0;
}

