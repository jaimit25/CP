#include "hp_desktop.hpp"
#include "dell_desktop.hpp"
#include "desktopDirector.hpp"
#include<iostream> 
using namespace std;

int main(){

	hp_desktopBuilder* hpdeskBuilder = new hp_desktopBuilder();
	dell_desktopBuilder* delldeskBuilder = new dell_desktopBuilder();

	DesktopDirector* d1 = new DesktopDirector(hpdeskBuilder);
	DesktopDirector* d2 = new DesktopDirector(delldeskBuilder);

	Desktop*desktop1 = d1->buildDesktop();
	Desktop*desktop2 = d2->buildDesktop();

	desktop1->showSpecs();
	desktop2->showSpecs();

	return 0;
}