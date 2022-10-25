import pygame
import sys
import math

SCREEN_HEIGHT = 480
SCREEN_WIDTH = SCREEN_HEIGHT * 2
MAP_SIZE = 8
TILE_SIZE = int((SCREEN_WIDTH / 2) / MAP_SIZE)
MAX_DEPTH = int(MAP_SIZE * TILE_SIZE)
FOV = math.pi / 3
HALF_FOV = FOV / 2
CASTED_RAYS = 120
STEP_ANGLE = FOV / CASTED_RAYS
SPEED_MOVE = 3
SCALE = (SCREEN_WIDTH / 2) / CASTED_RAYS

MAP = (
    '########'
    '# #    #'
    '# # ####'
    '#      #'
    '#      #'
    '#  ##  #'
    '#   #  #'
    '########'
)

player_x = (SCREEN_WIDTH / 2) / 2
player_y = SCREEN_HEIGHT / 2
player_angle = math.pi

pygame.init()
win = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT ))
pygame.display.set_caption("raycasting python")
clock = pygame.time.Clock()

def draw_map():
    pygame.draw.rect(
        win,
        (0, 0, 0),
        (0, 0, SCREEN_HEIGHT, SCREEN_HEIGHT)
        )
    for row in range(8):
        for col in range(8):
            square = row * MAP_SIZE + col
            pygame.draw.rect(
                win,
                (200, 200, 200) if MAP[square] == '#' else (100,100,100),
                (col * TILE_SIZE, row * TILE_SIZE, TILE_SIZE - 2, TILE_SIZE - 2)
                )

def draw_world():
    pygame.draw.rect(win, (100, 100, 100), (SCREEN_HEIGHT, SCREEN_HEIGHT / 2, SCREEN_HEIGHT, SCREEN_HEIGHT))
    pygame.draw.rect(win, (200, 200, 200), (SCREEN_HEIGHT, -SCREEN_HEIGHT / 2, SCREEN_HEIGHT, SCREEN_HEIGHT))


def draw_player():
    pygame.draw.circle(win, (255, 0, 0), (player_x, player_y), 8)
    # player direction
    pygame.draw.line(win, (0, 255, 0), (player_x, player_y), (
        player_x - math.sin(player_angle) * 50, 
        player_y + math.cos(player_angle) * 50
    ), 3)
    pygame.draw.line(win, (0, 255, 0), (player_x, player_y), (
        player_x - math.sin(player_angle - HALF_FOV) * 50, 
        player_y + math.cos(player_angle - HALF_FOV) * 50
    ), 3)
    pygame.draw.line(win, (0, 255, 0), (player_x, player_y), (
        player_x - math.sin(player_angle + HALF_FOV) * 50, 
        player_y + math.cos(player_angle + HALF_FOV) * 50
    ), 3)

def cast_rays():
    # first cast left
    start_angle = player_angle - HALF_FOV

    for ray in range(CASTED_RAYS):
        for depth in range(MAX_DEPTH):
            target_x = player_x - math.sin(start_angle) * depth
            target_y = player_y + math.cos(start_angle) * depth
            col = int(target_x / TILE_SIZE)
            row = int(target_y / TILE_SIZE)
            square = row * MAP_SIZE + col
            if MAP[square] == '#':
                pygame.draw.rect(
                    win,
                    (0, 255, 0),
                    (col * TILE_SIZE, row * TILE_SIZE, TILE_SIZE - 2, TILE_SIZE - 2)
                    )
                #color gradient
                color = 255 / (1 + depth * depth * 0.0001)
                #cat fish eye
                depth *= math.cos(player_angle - start_angle)
                #projection
                wall_height = 21000 / (depth + 0.00001)
                pygame.draw.rect(win, (color, color, color), (SCREEN_HEIGHT + ray * SCALE, (SCREEN_HEIGHT / 2) - wall_height / 2, SCALE, wall_height))                

                break
        pygame.draw.line(win, (0, 255, 0), (player_x, player_y), (target_x, target_y), 1)
        start_angle += STEP_ANGLE

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit(0)
    keys = pygame.key.get_pressed()
    if keys[pygame.K_ESCAPE]:
        pygame.quit()
        sys.exit(0)
    if keys[pygame.K_LEFT]:
        player_x += math.sin(player_angle + (math.pi / 2)) * SPEED_MOVE
        player_y += -math.cos(player_angle + (math.pi / 2)) * SPEED_MOVE
    if keys[pygame.K_RIGHT]:
        player_x += -math.sin(player_angle + (math.pi / 2)) * SPEED_MOVE
        player_y += math.cos(player_angle + (math.pi / 2)) * SPEED_MOVE
    if keys[pygame.K_a]: player_angle -= 0.1
    if keys[pygame.K_d]: player_angle += 0.1
    if keys[pygame.K_UP]:
        player_x += -math.sin(player_angle) * SPEED_MOVE
        player_y += math.cos(player_angle) * SPEED_MOVE
    if keys[pygame.K_DOWN]:
        player_x += math.sin(player_angle) * SPEED_MOVE
        player_y += -math.cos(player_angle) * SPEED_MOVE
    draw_map()
    draw_world()
    draw_player()
    cast_rays()
    pygame.display.flip()
    clock.tick(30)