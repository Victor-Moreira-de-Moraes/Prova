#include <stdio.h>
#include <unistd.h> // Para a função sleep()

int main(){
	for(;;) {
	    // Leia o estado do botão (HIGH ou LOW)
	    int estadoBotao = digitalRead(pinoBotao);
	
	    // Lidar com transições de estado
	    switch (estadoAtual) {
	        case LIGADO:
	            if (estadoBotao == DESLIGADO) {
	                // Botão solto, mude para o estado PROTEGIDO
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
	                // Botão pressionado novamente, volte para o estado LIGADO
	                estadoAtual = LIGADO;
	            }
	            break;
	    }
	}
	return 0;
}

