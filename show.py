import pygame, sys, math

pygame.init()
clock = pygame.time.Clock()

screenx,screeny = 1000,800

screen = pygame.display.set_mode([screenx,screeny])
pygame.display.set_caption("Sine Function")

xi = 700
yi = 350

vel = 0
acc = 1
ang = 0

r = 100
startx = xi - r - 50
history = []

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

    screen.fill((0,0,0))

    ang -= 0.02;
    x = math.cos(ang) * r + xi
    y = math.sin(ang) * r + yi

    pygame.draw.circle(screen, (255,255,255), (xi,yi), r, 3)

    pygame.draw.line(screen, (255,255,255), (xi-r,yi), (xi+r,yi))
    pygame.draw.line(screen, (255,255,255), (xi,yi+r), (xi,yi-r))

    pygame.draw.circle(screen, (255,255,255), (x,y), 10);

    pygame.draw.line(screen, (255,255,255), (x,y), (startx,y))

    history.append([startx,y])
    for point in history:
        point[0] -= 0.2
        pygame.draw.circle(screen, (0,255,255), point, 1)
    history = [point for point in history if point[0] > 50]

    pygame.display.flip()
    clock.tick(60)
    pygame.display.update()
