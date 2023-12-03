/*
Kenneth Guillont
Kenneth.Guillont83@myhunter.cuny.edu
Lab 9 Task A
*/

#include <iostream>
#include <cmath>

using namespace std;

class Coord3D {
public:
    double x;
    double y;
    double z;
};

class Particle {
public:
    Coord3D position;
    Coord3D velocity;

    Particle(double x, double y, double z, double vx, double vy, double vz)
    {
        position.x = x;
        position.y = y;
        position.z = z;
        velocity.x = vx;
        velocity.y = vy;
        velocity.z = vz;
    }
};

Coord3D* createCoord3D(double x, double y, double z)
{
    Coord3D* pos = new Coord3D;
    pos->x = x;
    pos->y = y;
    pos->z = z;

    return pos;
}

void deleteCoord3D(Coord3D* p)
{
    delete p;
}

double length(Coord3D* p)
{
    double len;
    len = sqrt(pow(p->x, 2) + pow(p->y, 2) + pow(p->z, 2));
    return len;
}

Particle* createParticle(double x, double y, double z, double vx, double vy, double vz)
{
    Particle* p = new Particle(x, y, z, vx, vy, vz);
    return p;
}

void setVelocity(Particle* p, double vx, double vy, double vz)
{
    p->velocity.x = vx;
    p->velocity.y = vy;
    p->velocity.z = vz;
}

Coord3D* fartherFromOrigin(Coord3D* p1, Coord3D* p2)
{
    double a = length(p1);
    double b = length(p2);

    if (a < b)
        return p2;
    else
        return p1;
}

Coord3D getPosition(Particle* p)
{
    return p->position;
}

void move(Particle* p, double dt)
{
    p->position.x += p->velocity.x * dt;
    p->position.y += p->velocity.y * dt;
    p->position.z += p->velocity.z * dt;
}

void deleteParticle(Particle* p)
{
    delete p;
}

int main()
{
    Particle* p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
    double time = 0.0;
    double dt = 0.1;
    while (time < 3.0) {
        setVelocity(p, 10.0 * time, 0.3, 0.1);
        move(p, dt);
        time += dt;
        cout << "Time: " << time << "\t";
        cout << "Position: " << getPosition(p).x << ", " << getPosition(p).y << ", " << getPosition(p).z << endl;
    }
    deleteParticle(p);

    return 0;
}
