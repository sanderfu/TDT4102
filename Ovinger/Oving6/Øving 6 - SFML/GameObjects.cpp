#include "GameObjects.h"

#include "cannonball.h"
#include <cmath>


Target::Target(double size,double position) {
	shape = sf::RectangleShape(sf::Vector2f(size, size));
	shape.setFillColor(sf::Color::Cyan);
	shape.setPosition(position, size/2);
	shape.setOrigin(size / 2, size / 2);
}

void Target::draw(sf::RenderWindow &window) {
	window.draw(shape);
}

// implement all (member) functions in this file

bool hitTarget(const Cannonball& c, const Target& t) {
    return c.shape.getGlobalBounds().intersects(t.shape.getGlobalBounds());
}

double Cannonball::getPosX() const {
	return posX(startPosX, startVelX, getAirTime());
}

double Cannonball::getPosY() const {
	return posY(startPosY, startVelY, getAirTime());
}

bool Cannonball::hasLanded() const {
    return getPosY() + size < 0;
}

void Cannonball::update(){
	shape.setPosition(getPosX(), getPosY());
}

void Cannonball::draw(sf::RenderWindow & window){
	window.draw(shape);
}

Cannonball::Cannonball(double angle, double initial_velocity, double startPosX, double startPosY){
	startVelX = getVelocityX(angle, initial_velocity);
	startVelY = getVelocityY(angle, initial_velocity);
	this->startPosX = startPosX;
	this->startPosY = startPosY;
	shape = sf::CircleShape(size);
	shape.setOrigin(size, size);
	shape.setFillColor(sf::Color::Red);
}

double Cannonball::getAirTime() const {
    return SPEED_FACTOR*clock.getElapsedTime().asSeconds();
}


Cannon::Cannon(){
	shape = sf::RectangleShape(sf::Vector2f(length, width));
	shape.setFillColor(sf::Color::Red);
	shape.setOrigin(width / 2, 0);
	shape.setPosition(0, 0);
	
}

double Cannon::getTipX() const {
    return length*cos(degToRad(theta));
}

double Cannon::getTipY() const {
    return length*sin(degToRad(theta));
}

void Cannon::incrementAngle(double dtheta){
	theta += dtheta;
}

void Cannon::decrementAngle(double dtheta){
	theta -= dtheta;
}

void Cannon::incrementVelocity(double dvel){
	velocity += dvel;
}

void Cannon::decrementVelocity(double dvel){
	velocity -= dvel;
}

Cannonball Cannon::shoot(){
	double angle = theta;
	double initial_velocity = velocity;
	double startPosX = getTipX();
	double startPosY = getTipY();
	Cannonball theBall(angle, initial_velocity, startPosX, startPosY);
	return theBall;
}

void Cannon::update(){
	shape.setRotation(theta);
}

void Cannon::draw(sf::RenderWindow & window){
	window.draw(shape);
}


