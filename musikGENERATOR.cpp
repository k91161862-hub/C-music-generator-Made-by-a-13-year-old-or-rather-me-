#include "mskgen.hpp"

int main() {
int variable;
int size;
while (true) {
print("1. Undertale Music\n2. Generate");
learn(variable);

switch (variable) {

case 1:
#pragma region Undertale Music

beep(294, 120); beep(294, 120); 
wait(120);
beep(1174, 240); 
wait(120);
beep(880, 180); 
wait(180);
beep(830, 240); 
wait(120);
beep(784, 240); 
wait(120);
beep(698, 240); 
wait(120);
beep(587, 120);  
beep(698, 120);  
beep(784, 120);  
wait(120);

beep(587, 120); beep(587, 120);
wait(120);
beep(1174, 240); 
wait(120);
beep(880, 180);  
wait(180);
beep(830, 240);  
wait(120);
beep(784, 240);  
wait(120);
beep(698, 240);  
wait(120);
beep(587, 120);  
beep(698, 120);  
beep(784, 120);  
wait(120);


beep(494, 120); beep(494, 120);
wait(120);
beep(1174, 240); 
wait(120);
beep(880, 180);  
wait(180);
beep(830, 240);  
wait(120);
beep(784, 240);  
wait(120);
beep(698, 240);  
wait(120);
beep(587, 120);  
beep(698, 120);  
beep(784, 120);  
wait(120);


beep(440, 120); beep(440, 120);
wait(120);
beep(1174, 240); 
wait(120);
beep(880, 180);  
wait(180);
beep(830, 240);  
wait(120);
beep(784, 240);  
wait(120);
beep(698, 240);  
wait(120);
beep(587, 120);  
beep(698, 120);  
beep(784, 120);  
wait(120);

#pragma endregion
CLEAR_CONSOLE;
break;

case 2:
print("Music size: ");
learn(size);
autobeep(size);
CLEAR_CONSOLE;
break;
}
}
return 0;
}