#include <stdio.h>
#include <allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include "constants.h"
#include <iostream>
using namespace std;
#include "marble.h"


const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;


int main()
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;

	bool redraw = true;

	al_init();
	al_init_primitives_addon();
	al_install_mouse();

	timer = al_create_timer(1.0 / FPS);
	

	display = al_create_display(SCREEN_W, SCREEN_H);
	

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();


	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_mouse_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);


	//initalize pieces
	marble m1;
	m1.initMarble(50,50);


	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
		}

		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES && m1.isLifted()) {
			m1.move(ev.mouse.x, ev.mouse.y);
			
		}

		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			cout << "CLICK";
			if (m1.clicked(ev.mouse.x, ev.mouse.y))
				if (m1.isLifted() == false)
					m1.liftUp();
				else {
					m1.PutDown();
				}
		}

		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			
		}




		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

		

			m1.draw();

			al_flip_display();
		}
	}


	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}