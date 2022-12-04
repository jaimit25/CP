#include<bits/stdc++.h>
using namespace std;

//interface - button 
class IButton 
{
	public : 
	virtual void press() = 0 ; 

};

//windows - button 
class MacButton : public IButton{
	public : 
	void press (){
		cout<<"Mac Button press "<<endl;
	}
};
// mac - button 
class WindowsButton : public IButton{
	public : 
	void press (){
		cout<<"Windows Button press "<<endl;
	}
};
// __________________________

//interface - text box
class ITextBox
{
	public : 
	virtual void showtext() = 0 ; 

};

// mac  - text box
class MacTextBox : public ITextBox{
	public : 
	void showtext (){
		cout<<"Mac text "<<endl;
	}
};

//windows - text box
class WindowsTextBox : public ITextBox{
	public : 
	void showtext (){
		cout<<"Windows text "<<endl;
	}
};

// __________________________


class IFactory{
	public : 
	virtual  IButton* CreateButton() = 0;
	virtual  ITextBox* CreateTextBox() = 0;
};


class MacFactory :public  IFactory{
	public : 
	IButton* CreateButton(){
		return new MacButton();
	}
	ITextBox* CreateTextBox(){
		return new MacTextBox();
	}
};

class WindowsFactory :public  IFactory{
	public : 
	IButton* CreateButton(){
		return new WindowsButton();
	}
	ITextBox* CreateTextBox(){
		return new WindowsTextBox();
	}
};



// __________________________

class GUIAbstractFactory{
	public :
	 static IFactory* CreateFactory(string osType){
		if(osType == "mac"){
			return new MacFactory();

		}else if(osType == "win"){
			return new WindowsFactory();
		}
		else return new WindowsFactory();
	 }
};


// __________________________


int main()
{
cout <<" Enter Your machine OS : "<<endl; 

string os;
cin >> os;


//interface Ifactory
IFactory* fac = GUIAbstractFactory::CreateFactory(os);
 
IButton* button = fac->CreateButton(); //tell factory to create a btn and give no matter os.
button->press();

ITextBox* textbox = fac->CreateTextBox(); //tell factory to create a btn and give no matter os.
textbox->showtext();

return 0;
}
 