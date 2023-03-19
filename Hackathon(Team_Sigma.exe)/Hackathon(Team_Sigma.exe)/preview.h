#pragma once
#include <SFML/Graphics.hpp>
#include "third_page.h"

void preView(generalinfo geninfo, socialinfo socinfo, jobinfo businfo, educationinfo eduinfo, adlinfo addInfo, string finalname) {
	sf::RenderWindow loveisded(sf::VideoMode(960, 720), "PREVIEW", sf::Style::Close);
	sf::RectangleShape largeBG,pic;
	largeBG.setSize(sf::Vector2f(960, 1200));
	pic.setSize(sf::Vector2f(150, 200));
	pic.setPosition(780, 50);
	sf::Texture tex,picc;
	tex.loadFromFile("light.jpg");
	picc.loadFromFile("face.jpg");
	largeBG.setTexture(&tex);
	pic.setTexture(&picc);
	sf::Text text[25];
	sf::Font font;
	font.loadFromFile("arial.ttf");
	for (int i = 0; i < 25; i++) {
		text[i].setFont(font);
		text[i].setCharacterSize(25);
		text[i].setFillColor(sf::Color::Black);
	}
	text[0].setString("Name: " + geninfo.firstname + geninfo.lastname);
	text[1].setString("Date of Birth: " + geninfo.dateofbirth);
	text[2].setString("Nationality: " + geninfo.nationality);
	text[3].setString("Phone: " + socinfo.phone);
	text[4].setString("Email: " + socinfo.email);

	text[5].setString("EDUCATION\n");
	text[6].setString("----------------\n");
	text[7].setString("Institution: " + eduinfo.instname);
	text[8].setString("Location of Institute: " + eduinfo.instlocation);
	text[9].setString("Graduation Year: " + eduinfo.graduationyear);
	text[10].setString("Field of Study: " + eduinfo.fieldofstudy);
	text[11].setString("Qualification: " + eduinfo.qualification);

	text[12].setString("WORK EXPERIENCE");
	text[13].setString("----------------");
	text[14].setString("Name of Company: " + businfo.employer);
	text[15].setString("Designation: " + businfo.jobtitle);
	text[16].setString("Year: " + businfo.enddate);

	text[17].setString("ACTIVITIES AND INTERESTS");
	text[18].setString("----------------");
	text[19].setString("1) Proficient at languages " + addInfo.language);
	text[20].setString("2) My accomplishments include " + addInfo.accomplishment);
	text[21].setString("3) I have the following\n certifications : " + addInfo.certification);
	text[22].setString("4) I like to play " + addInfo.sports);
	text[23].setString("5) My hobbies and interests are " + addInfo.hobbies);
	text[24].setString("6) Other things I am interested in " + addInfo.extra);

	text[0].setPosition(50, 170);
	text[1].setPosition(50, 200);
	text[2].setPosition(50, 230);
	text[3].setPosition(50, 260);
	text[4].setPosition(50, 290);
	text[5].setPosition(450, 100);
	text[6].setPosition(450, 130);
	text[7].setPosition(450, 160);
	text[8].setPosition(450, 190);
	text[9].setPosition(450, 220);
	text[10].setPosition(450, 250);
	text[11].setPosition(450, 280);
	text[12].setPosition(50, 380);
	text[13].setPosition(50, 410);
	text[14].setPosition(50, 440);
	text[15].setPosition(50, 470);
	text[16].setPosition(50, 500);
	text[17].setPosition(450, 390);
	text[18].setPosition(450, 420);
	text[19].setPosition(450, 450);
	text[20].setPosition(450, 480);
	text[21].setPosition(450, 510);
	text[22].setPosition(450, 570);
	text[23].setPosition(450, 600);
	text[24].setPosition(450, 630);
	sf::Event novent;
	while (loveisded.isOpen()){
		while (loveisded.pollEvent(novent)) {
			if (novent.type == sf::Event::Closed) {
				loveisded.close();
			}

		}
	loveisded.clear();
	loveisded.draw(largeBG);
	loveisded.draw(pic);
	for (int i = 0; i < 25; i++) {
		loveisded.draw(text[i]);
	}
	loveisded.display();
	}

}

