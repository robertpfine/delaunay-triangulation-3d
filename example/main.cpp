#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <array>
#include <random>
#include <chrono>

#include <SFML/Graphics.hpp>

#include "vector3d.h"
#include "triangle3d.h"
#include "delaunay3d.h"


//dt::Vector3d TestTempInstan;

int main(int argc, char * argv[])
{
	int numberPoints = 15;
	if (argc>1)
	{
		numberPoints = atoi(argv[1]);
	}

	std::default_random_engine eng(std::random_device{}());
	std::uniform_real_distribution<double> dist_w(0, 800);
	std::uniform_real_distribution<double> dist_h(0, 600);
    std::uniform_real_distribution<double> dist_d(0, 5);

	std::cout << "Generating " << numberPoints << " random points" << std::endl;

	std::vector<dt::Vector3d<double>> points;
	for(int i = 0; i < numberPoints; ++i) {
		points.push_back(dt::Vector3d<double>{dist_w(eng), dist_h(eng), dist_d(eng)});

        std::cout
                << "position x: " << points[i].x
                << " position y: " << points[i].y
                << " position z: " << points[i].z
                << std::endl;
	}

	dt::Delaunay3d<double> triangulation;
	const auto start = std::chrono::high_resolution_clock::now();
	const std::vector<dt::Triangle3d<double>> triangles = triangulation.triangulate(points);
	const auto end = std::chrono::high_resolution_clock::now();
	const std::chrono::duration<double> diff = end - start;

	std::cout << triangles.size() << " triangles generated in " << diff.count()
			<< "s\n";

    for(int i = 0; i < triangles.size(); ++i) {
        //for(int j = 0; j < 3; j++)
        //    for(int m = 0; m < 2; m++)

        std::cout << "triangle: " << i <<  " "
                  << "vertex 1:" <<  "position x: " << triangles[i].a->x << " position y: " << triangles[i].a->y << " position z: " << triangles[i].a->z
                  << "vertex 2:" <<  "position x: " << triangles[i].b->x << " position y: " << triangles[i].b->y << " position z: " << triangles[i].b->z
                  << "vertex 3:" <<  "position x: " << triangles[i].c->x << " position y: " << triangles[i].c->y << " position z: " << triangles[i].c->z
                  << std::endl;
    }


    const std::vector<dt::Edge3d<double>> edges = triangulation.getEdges();

	// SFML window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Delaunay triangulation");
	window.setFramerateLimit(1);

	// Transform each points of each vector as a rectangle
	for(const auto p : points) {
		sf::RectangleShape s{sf::Vector2f(4, 4)};
		s.setPosition(static_cast<float>(p.x), static_cast<float>(p.y));
		window.draw(s);
	}

	std::vector<std::array<sf::Vertex, 2> > lines;
	for(const auto &e : edges) {
		const std::array<sf::Vertex, 2> line{{
			sf::Vertex(sf::Vector2f(
					static_cast<float>(e.v->x + 2.),
					static_cast<float>(e.v->y + 2.))),
			sf::Vertex(sf::Vector2f(
					static_cast<float>(e.w->x + 2.),
					static_cast<float>(e.w->y + 2.))),
		}};
		window.draw(line.data(), 2, sf::Lines);
	}

	window.display();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}

	return 0;
}
