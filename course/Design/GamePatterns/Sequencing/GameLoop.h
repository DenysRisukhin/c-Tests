//
//  GameLoop.h
//  Test2019
//
//  Created by Risukhin Denys on 2/11/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef GameLoop_h
#define GameLoop_h

// Игровой цикл работает на протяжении всей игры, следит за ходом времени и управляет скоростью игрового процесса.
// На каждом своем шаге игровой цикл обрабатывает
// - пользовательский ввод
// - обновляет состояние игры
// - рендерит игру

// Ex 1
// doesn't control the spped
while (true){
    processInput();
    update();
    render();
}

// Ex 2
// FPS 60 - около 16 миллисекунд на кадр
// next frame time: 1000мс/FPS = mc на кадр
while (true) {
    double start = getCurrentTime();
    processInput();
    update();
    render();

    sleep(start + MS_PER_FRAME - getCurrentTime());
}


// Ex 3
double lastTime = getCurrentTime();
while (true)
{
    double current = getCurrentTime();
    double elapsed = current - lastTime;
    processInput();
    update(elapsed);
    render();
    lastTime = current;
}


// Ex 4
// elapsed - истек
double previous = getCurrentTime();
double lag = 0.0;
while (true)
{
    double current = getCurrentTime();
    double elapsed = current - previous;
    previous = current;
    lag += elapsed;

    processInput();
    
    while (lag >= MS_PER_UPDATE)
    {
        update();
        lag -= MS_PER_UPDATE;
    }

    render();
}

#endif /* GameLoop_h */
