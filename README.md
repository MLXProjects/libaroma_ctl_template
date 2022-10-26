# libaroma_ctl_template
Libaroma control template to learn how to create & add controls for https://github.com/MLXProjects/libaroma

# Notes
This template is pretty well documented I think, but I may have missed some things.  
Feel free to contact me in case you need any help :D

# How to add control to libaroma
1) put ctl_template.c at libaroma/src/aroma/controls  
2) put ctl_template.h at libaroma/include/aroma/controls  
3) add to libaroma/include/aroma/ui.h the following line:  
  ```#include "controls/ctl_template.h"```
4) rebuild libaroma

# License
This template is licensed under Apache 2.0 license, same as libaroma itself.
