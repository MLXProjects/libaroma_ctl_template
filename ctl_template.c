/********************************************************************[libaroma]*
 * Copyright (C) 2011-2015 Ahmad Amarullah (http://amarullz.com/)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *			http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *______________________________________________________________________________
 *
 * Filename		: ctl_template.c
 * Description : template control
 *
 * + This is part of libaroma, an embedded ui toolkit.
 * + 26/10/22 - Author(s): Michael Jauregui
 *
 */
#ifndef __libaroma_ctl_template_c__
#define __libaroma_ctl_template_c__
#include <aroma_internal.h>
#include "../ui/ui_internal.h"

/* HANDLER */
dword _libaroma_ctl_template_msg(LIBAROMA_CONTROLP, LIBAROMA_MSGP);
void _libaroma_ctl_template_draw (LIBAROMA_CONTROLP, LIBAROMA_CANVASP);
void _libaroma_ctl_template_destroy(LIBAROMA_CONTROLP);
byte _libaroma_ctl_template_thread(LIBAROMA_CONTROLP);

/* control handler provides callbacks to be called by libaroma */
static LIBAROMA_CONTROL_HANDLER _libaroma_ctl_template_handler={
	message:_libaroma_ctl_template_msg,
	draw:_libaroma_ctl_template_draw,
	focus:NULL,
	destroy:_libaroma_ctl_template_destroy,
	thread:_libaroma_ctl_template_thread
};

/*
 * Structure	 : __LIBAROMA_CTL_TEMPLATE
 * Typedef		 : _LIBAROMA_CTL_TEMPLATE, * _LIBAROMA_CTL_TEMPLATEP
 * Descriptions: libaroma_ctl_template control internal structure
 */
typedef struct __LIBAROMA_CTL_TEMPLATE _LIBAROMA_CTL_TEMPLATE;
typedef struct __LIBAROMA_CTL_TEMPLATE * _LIBAROMA_CTL_TEMPLATEP;
struct __LIBAROMA_CTL_TEMPLATE{
	/* flag to force redraw control */
	byte forcedraw;
	
	/* put any pointers/structs/variables you need here */
	//void *something;
	
	/* multithread safe mutex */
	//LIBAROMA_MUTEX mutex;
};

/*
 * Function		: _libaroma_ctl_template_msg
 * Return Value: byte
 * Descriptions: message callback
 */
dword _libaroma_ctl_template_msg(
		LIBAROMA_CONTROLP ctl,
		LIBAROMA_MSGP msg){
	/* internal check */
	_LIBAROMA_CTL_CHECK(
		_libaroma_ctl_template_handler, _LIBAROMA_CTL_TEMPLATEP, 0
	);

	switch(msg->msg){
		/* update control on receiving any of these window events */
		case LIBAROMA_MSG_WIN_ACTIVE:
		case LIBAROMA_MSG_WIN_INACTIVE:
		case LIBAROMA_MSG_WIN_RESIZE:{
			/* wait & lock mutex before updating control data */
			//libaroma_mutex_lock(me->mutex);
			printf("msg forcedraw libaroma_ctl_template\n");
			/* redraw control */
			me->forcedraw=1;
			/* unlock control data */
			//libaroma_mutex_unlock(me->mutex);
		} break;
	}
	return 0;
} /* End of _libaroma_ctl_template_msg */

/*
 * Function		: _libaroma_ctl_template_draw
 * Return Value: void
 * Descriptions: draw callback
 */
void _libaroma_ctl_template_draw(
		LIBAROMA_CONTROLP ctl,
		LIBAROMA_CANVASP c){
	printf("draw libaroma_ctl_template\n");
	/* internal check */
	_LIBAROMA_CTL_CHECK(
		_libaroma_ctl_template_handler, _LIBAROMA_CTL_TEMPLATEP,
		/* no third parameter means return nothing because of void function */
	);
	/* wait & lock control data */
	//libaroma_mutex_lock(me->mutex);
	
	/* copy window background into control canvas */
	libaroma_control_erasebg(ctl, c);
	
	/* do any drawing procedures here, like this (draw red rect on control canvas) */
	//libaroma_draw_rect(c, 0, 0, c->w, c->h, RGB(FF0000), 0xFF):
	
	/* unlock control data */
	//libaroma_mutex_unlock(me->mutex);
} /* End of _libaroma_ctl_template_draw */

/*
 * Function		: _libaroma_ctl_template_destroy
 * Return Value: void
 * Descriptions: destroy callback
 */
void _libaroma_ctl_template_destroy(
		LIBAROMA_CONTROLP ctl){
	/* internal check */
	_LIBAROMA_CTL_CHECK(
		_libaroma_ctl_template_handler, _LIBAROMA_CTL_TEMPLATEP,
		/* no third parameter means return nothing because of void function */
	);
	/* first wait to lock mutex so control data isn't used while being freed */
	//libaroma_mutex_lock(me->mutex);
	/* free any control data you have included (structs, pointer arrays, etc) */
	//free(me->something);
	/* now unlock & free mutex, then release control data */
	//libaroma_mutex_unlock(me->mutex);
	//libaroma_mutex_free(me->mutex);
	printf("destroy libaroma_ctl_template\n");
	free(me);
} /* End of _libaroma_ctl_template_destroy */

/*
 * Function		: _libaroma_ctl_template_thread
 * Return Value: byte
 * Descriptions: control thread callback
 */
byte _libaroma_ctl_template_thread(LIBAROMA_CONTROLP ctl) {
	/* internal check */
	_LIBAROMA_CTL_CHECK(
		_libaroma_ctl_template_handler, _LIBAROMA_CTL_TEMPLATEP, 0
	);
	byte need_draw = me->forcedraw;
	if (need_draw){
		printf("thread redraw libaroma_ctl_template\n");
		/* stop updating after this draw (draws control just once) */
		me->forcedraw=0;
		/* return 1 to signal that control needs to be drawn */
		return 1;
	}
	/* return 0 to not update this control */
	return 0;
} /* End of _libaroma_ctl_template_thread */

LIBAROMA_CONTROLP libaroma_ctl_template(
		LIBAROMA_WINDOWP win, word id,
		int x, int y, int w, int h){
	
	/* allocate internal data */
	_LIBAROMA_CTL_TEMPLATEP me = (_LIBAROMA_CTL_TEMPLATEP)
			calloc(sizeof(_LIBAROMA_CTL_TEMPLATE),1);
	if (!me){
		printf("libaroma_ctl_template alloc memory failed\n");
		return NULL;
	}

	/* init mutex and allocate any control data here */
	//libaroma_mutex_init(me->mutex);
	//me->something = malloc(sizeof(somesize));
	
	/* create libaroma control */
	LIBAROMA_CONTROLP ctl =
		libaroma_control_new(
			id,
			x, y, w, h,
			libaroma_dp(24),libaroma_dp(24), /* min size */
			(voidp) me,
			&_libaroma_ctl_template_handler,
			win
		);
	if (!ctl){
		/* if failed release mutex, control data and internal struct */
		//libaroma_mutex_free(me->mutex);
		//free(me->something);
		free(me);
		return NULL;
	}
	/* if succeeded return pointer to control */
	return ctl;
}

/*
 * Function		: libaroma_ctl_template_update
 * Return Value: byte
 * Descriptions: update control
 */
byte libaroma_ctl_template_update(LIBAROMA_CONTROLP ctl){
	/* internal check */
	_LIBAROMA_CTL_CHECK(
		_libaroma_ctl_template_handler, _LIBAROMA_CTL_TEMPLATEP, 0
	);
	me->forcedraw=1;
	return 1;
} /* End of libaroma_ctl_template_update */

#endif /*__libaroma_ctl_template_c__*/