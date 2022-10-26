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
 * Filename		: ctl_template.h
 * Description : template control
 *
 * + This is part of libaroma, an embedded ui toolkit.
 * + 26/10/22 - Author(s): Michael Jauregui
 *
 */
#ifndef __libaroma_aroma_h__
	#error "Include <aroma.h> instead."
#endif
#ifndef __libaroma_ctl_template_h__
#define __libaroma_ctl_template_h__

LIBAROMA_CONTROLP libaroma_ctl_template(
		LIBAROMA_WINDOWP win, word id,
		int x, int y, int w, int h
);

byte libaroma_ctl_template_update(LIBAROMA_CONTROLP ctl);

#endif /*__libaroma_ctl_template_h__*/