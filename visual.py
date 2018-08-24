# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    visual.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avo <avo@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/24 17:03:00 by avo               #+#    #+#              #
#    Updated: 2018/08/24 19:13:23 by avo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import pygame
import sys
 
pygame.init()
width = 350
height = 200

if (len(sys.argv) == 1):
    print("Program received signal SIGSEGV, Segmentation fault.\n")
    exit(-1)
with open(sys.argv[1], 'r') as my_file:
    ret = my_file.readline()
    print("first line == %s\n" %(ret))
    mov = my_file.read().split()
    # print("and the rest %s\n" %(mov)
    
#make the pygame window
pygame.display.set_mode((width, height ) )
print(ret)
print(mov)
running = True

while (running):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False