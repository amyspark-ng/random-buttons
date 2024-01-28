#include <Geode/Geode.hpp>
#include <Geode/modify/CreatorLayer.hpp>

#include <Geode/cocos/menu_nodes/CCMenu.h>

#include <algorithm>
#include <iostream>
#include <random>

using namespace geode::prelude;

class $modify(CreatorLayer) {
	bool init() {
	if (!CreatorLayer::init())
		return false;

		// Ignore my terrible not-DRY friendly code
		CCNode * creatorLayerBtns[15] = {
			{this->getChildByID("creator-buttons-menu")->getChildByID("featured-button")},
			{this->getChildByID("creator-buttons-menu")->getChildByID("lists-button")},
			{this->getChildByID("creator-buttons-menu")->getChildByID("paths-button")},
			{this->getChildByID("creator-buttons-menu")->getChildByID("map-packs-button")},
			{this->getChildByID("creator-buttons-menu")->getChildByID("search-button")},
			{this->getChildByID("creator-buttons-menu")->getChildByID("map-button")},
			{this->getChildByID("creator-buttons-menu")->getChildByID("daily-button")},
			{this->getChildByID("creator-buttons-menu")->getChildByID("weekly-button")},
			{this->getChildByID("creator-buttons-menu")->getChildByID("event-button")},
			{this->getChildByID("creator-buttons-menu")->getChildByID("gauntlets-button")},
			{this->getChildByID("creator-buttons-menu")->getChildByID("create-button")},
			{this->getChildByID("creator-buttons-menu")->getChildByID("saved-button")},
			{this->getChildByID("creator-buttons-menu")->getChildByID("scores-button")},
			{this->getChildByID("creator-buttons-menu")->getChildByID("quests-button")},
			{this->getChildByID("creator-buttons-menu")->getChildByID("versus-button")},
		};

		CCPoint btnsPos[15] = {
			{creatorLayerBtns[0]->getPosition()},
			{creatorLayerBtns[1]->getPosition()},
			{creatorLayerBtns[2]->getPosition()},
			{creatorLayerBtns[3]->getPosition()},
			{creatorLayerBtns[4]->getPosition()},
			{creatorLayerBtns[5]->getPosition()},
			{creatorLayerBtns[6]->getPosition()},
			{creatorLayerBtns[7]->getPosition()},
			{creatorLayerBtns[8]->getPosition()},
			{creatorLayerBtns[9]->getPosition()},
			{creatorLayerBtns[10]->getPosition()},
			{creatorLayerBtns[11]->getPosition()},
			{creatorLayerBtns[12]->getPosition()},
			{creatorLayerBtns[13]->getPosition()},
			{creatorLayerBtns[14]->getPosition()},
		};

		// Seed for the random number generator
		std::random_device rd;
		// Use Mersenne Twister engine
		std::mt19937 gen(rd());

		// Fisher-Yates shuffle
		for (int i = 15 - 1; i > 0; --i) {
			std::uniform_int_distribution<int> dist(0, i);
			int j = dist(gen);

			// Swap elements
			std::swap(btnsPos[i], btnsPos[j]);
		}

		// Sets the new position to the buttons
		for(int i = 0; i < 15; i++) {
			creatorLayerBtns[i]->setPosition(btnsPos[i]);
		}

		return true;
	}

};