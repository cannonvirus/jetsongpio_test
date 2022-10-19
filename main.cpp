#include <iostream>
#include <signal.h>
#include <chrono>
#include <thread>
#include <JetsonGPIO.h>

using namespace std;

static bool end_this_program = false;

inline void delay(int s) { this_thread::sleep_for(chrono::seconds(s)); }

void signalHandler(int s) { end_this_program = true; }

int main()
{
    // When CTRL+C pressed, signalHandler will be called
    signal(SIGINT, signalHandler);

    // Pin Definitions
    // int but_pin = 11; // BOARD pin 11 13 19 21 23 29 31
    static int but_pin_11 = 11;
    static int but_pin_13 = 13;
    static int but_pin_19 = 19;
    static int but_pin_21 = 21;
    static int but_pin_23 = 23;
    static int but_pin_29 = 29;
    static int but_pin_31 = 31;

    // Pin Setup.
    GPIO::setmode(GPIO::BOARD);

    // set pin as an output pin with optional initial state of LOW
    // GPIO::setup(but_pin, GPIO::IN);
    GPIO::setup(but_pin_11, GPIO::IN);
    GPIO::setup(but_pin_13, GPIO::IN);
    GPIO::setup(but_pin_19, GPIO::IN);
    GPIO::setup(but_pin_21, GPIO::IN);
    GPIO::setup(but_pin_23, GPIO::IN);
    GPIO::setup(but_pin_29, GPIO::IN);
    GPIO::setup(but_pin_31, GPIO::IN);

    cout << "Starting demo now! Press CTRL+C to exit" << endl;

    while (!end_this_program)
    {
        // // NOTE : 1초에 한번씩 value 확인하는 코드
        // int value = GPIO::input(but_pin);
        // cout << "button : " << boolalpha << bool(value) << endl;
        // delay(0.05);

        // NOTE : 입력값 올 떄까지 기다리기
        // int value = GPIO::input(but_pin);
        // GPIO::WaitResult result = GPIO::wait_for_edge(but_pin, GPIO::RISING);
        // if (result.is_event_detected()) {
        //     // NOTE : 주의 false, true 섞여서 들어옴. if문 event로만 사용할 것
        //     cout << "button : " << boolalpha << bool(value) << endl;
        // }

        GPIO::add_event_detect(but_pin_11, GPIO::RISING);
        GPIO::add_event_detect(but_pin_13, GPIO::RISING);
        GPIO::add_event_detect(but_pin_19, GPIO::RISING);
        GPIO::add_event_detect(but_pin_21, GPIO::RISING);
        GPIO::add_event_detect(but_pin_23, GPIO::RISING);
        GPIO::add_event_detect(but_pin_29, GPIO::RISING);
        GPIO::add_event_detect(but_pin_31, GPIO::RISING);

        if (GPIO::event_detected(but_pin_11)) cout << "age+" << endl;
        if (GPIO::event_detected(but_pin_13)) cout << "age-" << endl;
        if (GPIO::event_detected(but_pin_19)) cout << "flip" << endl;
        if (GPIO::event_detected(but_pin_21)) cout << "direction" << endl;
        if (GPIO::event_detected(but_pin_23)) cout << "reset" << endl;
        if (GPIO::event_detected(but_pin_29)) cout << "bias+" << endl;
        if (GPIO::event_detected(but_pin_31)) cout << "bias-" << endl;

    }

    GPIO::cleanup();

    return 0;
}
