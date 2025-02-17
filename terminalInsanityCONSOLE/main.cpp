﻿// © Copyright 2021 Ongakken s.r.o. All rights reserved.
//   Terminal Insanity, Ongakken, the alternative names オンガッケン,  オンがッけン, the Ongakken logo, the Ongakken symbol, the Ongakken pattern are trademarks of Ongakken s.r.o.
//   Based on a 2016 videogame 'Terminal Insanity' by Simon Slamka

#include "main.h"

// using namespace std; //standard namespace for using cout, cin and some other without defining the namespace they're in (std::cout)

uint64_t constexpr mix(char m, uint64_t s)
{
	return ((s << 7) + ~(s >> 3)) + ~m;
}

uint64_t constexpr hashIt(const char* m)
{
	return (*m) ? mix(*m, hashIt(m + 1)) : 0;
}

int main() {
	core Core; // instantiate a 'Core' object of the 'core' class
	char hostname[HOST_NAME_MAX + 1]; // define a char var 'hostname' with the max_len of 65 bytes;
	gethostname(hostname, HOST_NAME_MAX + 1); // use the gethostname() system call from unistd.h to get the current local machine's hostname
	cout << "Terminal Insanity 0.00.1 @ " << hostname << flush << endl; // print the hostname after the game name + version
	Core.bInteractiveShell = false; // set the in-game shell interaction bool to false (default)
	Core.init();
	Core.boot();
	Core.lvl1();
	Core.boot();
	Core.lvl2(Core); // here we're passing the instantiated object 'Class' to the function lvl2(), which is expecting a pointer to the 'core' class
	return 0;
}

void core::iterateOverString(string &playerMsg, int s, int long ns) {
	struct timespec ts = { s, ns };
	for(long unsigned int i = 0; i < playerMsg.size(); i++)
	{
		cout << playerMsg[i] << flush; // <3 from @simonSlamka to @aleksandrazb for solving this one :3 this method was her idea
		nanosleep(&ts, NULL);
	}
}

void core::evaluateCmdInput(const char* cmdInputChar)
{
	switch(hashIt(cmdInputChar))
	{
		case hashIt("whoami"):
			whoami();
			break;
		case hashIt("who"): // @todo Create the ability to pass arguments to the in-game shell's commands @body So basically we're gonna pass arguments into functions that handle the functionality of the game's in-game shell comands, for example: man sudo, where man is a command and sudo is an argument
			// code
			break;
		case hashIt("exit"):
			// do nothing
			break;
		default:
			cout << "ongashell: command not found: " << cmdInputChar << endl;
			break;
	};
}

int core::whoami()
{
	cout << "j3ff\n";
	return 0;
}

void core::spawnShell(core& Core)
{
	while(Core.bInteractiveShell)
	{
		cout << "$ ";
		cin >> Core.cmdInput;
		const char* cmdInputChar = Core.cmdInput.c_str();
		Core.evaluateCmdInput(cmdInputChar);
		if(cmdInput == "exit")
		{
			break;
			Core.bInteractiveShell = false;
		}
	}
}

void core::init() {
	// string x;
	system("/usr/bin/zsh -c '[ -d /opt/ongakken/terminalInsanity ] && [ -d /opt/ongakken/terminalInsanity/sounds ] && [ -d /opt/ongakken/terminalInsanity/img ] && printf '\a''");
	sleep(1);
	system("grep 'zsh' /etc/shells >> /dev/null && printf '\a'");
	sleep(1);
	system("./zshVerify >> /dev/null && printf '\a'");
	sleep(1);
	system("kitty -o allow_remote_control=yes --title OngakkenLogo --listen-on unix:/tmp/terminalInsanity --hold viu /opt/ongakken/logo.png &");
	system("paplay /opt/ongakken/terminalInsanity/sounds/intro.wav &");
	struct timespec ts = { 0, 2000000000 };
	nanosleep(&ts, NULL);
	system("killall paplay");
	sleep(1);
	system("kitty @ --to unix:/tmp/terminalInsanity close-window --match title:OngakkenLogo");
}

void core::boot() {
	cout << "\033]0;" << "Terminal" << "\007";
	system("clear");
	cout << "Booting ...\n\n";
	sleep(2);
	system("printf '[\e[32mOK\e[0m] Mounting the root filesystem ...\n'");
	cout << "\n";
	sleep(2);
	system("printf '[\e[32mOK\e[0m] Running /sbin/init ...\n'");
	cout << "\n";
	sleep(1);
	system("printf '[\e[32mOK\e[0m] Starting runlevel programs ...\n'");
	cout << "\n";
	sleep(1);
	ifstream f("/opt/ongakken/terminalInsanity/dmesg");
	if (f.is_open()) {
	cout << f.rdbuf();
	}
	cout << "\n";
	system("printf '[\e[31mFAIL\e[0m] Scanning for friendly network devices ...\n'");
	cout << "\n";
	sleep(4);
	system("printf '[\e[32mOK\e[0m] Running post-boot runlevel subroutine 'readme' ...'");
	sleep(1);
	system("clear");
}

void core::lvl1() {
	cout << "\033]0;" << "Terminal" << "\007";
	system("clear");
	sleep(3);
	cout << "IRC channel connection established\n\n";
	cout << "------------------------------------";
	cout << "\n";
	cout << "\n\n";
	sleep(3);
	system("printf '\e[34mJason:\e[0m we need to figure something out ...\n'");
	cout << "\n";
	sleep(4);
	system("printf '\e[95mMark:\e[0m agreed, we cannot just sit and do nothin\n'");
	cout << "\n";
	sleep(6);
	system("printf '\e[34mJason:\e[0m where is J3ff btw?\n'");
	cout << "\n";
	sleep(3);
	system("printf '\e[95mMark:\e[0m idk\n'");
	cout << "\n";
	sleep(4);
	system("printf '%s' '\e[36mJ3ff:\e[0m'");
	playerMsg = (" Hey guys");
	iterateOverString(playerMsg, 0, 100000000);
	cout << "\n\n";
	sleep(6);
	system("printf '\e[95mMark:\e[0m nice of you to finally show up..\n'");
	cout << "\n";
	sleep(1);
	system("printf '\e[34mJason:\e[0m hey man\n'");
	sleep(7);
	system("printf '\e[34mJason:\e[0m we were just discussing the plan\n'");
	cout << "\n";
	sleep(3);
	system("printf '%s' '\e[36mJ3ff:\e[0m'");
	playerMsg = (" So how are we gonna do it?");
	iterateOverString(playerMsg, 0, 100000000);
	cout << "\n\n";
	sleep(9);
	system("printf '\e[95mMark:\e[0m well, for starters, we need more people.\n'");
	sleep(7);
	system("printf '\e[95mMark:\e[0m even though we can do it skill-wise, we do not have time, so we need more firepower\n'");
	sleep(11);
	system("printf '\e[95mMark:\e[0m i have an idea, but it requires putting aurora up to a difficult recursive search task\n'");
	sleep(12);
	system("printf '\e[95mMark:\e[0m so j3ff, do i have your permission to access her and run the code i wrote?\n'");
	cout << "\n";
	sleep(4);
	system("printf '%s' '\e[36mJ3ff:\e[0m'");
	playerMsg = (" Alright, try it. We need this to happen.");
	iterateOverString(playerMsg, 0, 100000000);
	cout << "\n\n";
	sleep(5);
	system("printf '\e[95mMark:\e[0m roger. on it\n'");
	cout << "\n\n";
	sleep(4);
	system("printf '%s' '\e[33mA week later ...\e[0m\n' | pv -qL 3"); // I'm keeping the 'pv' approach here just in case, so we'll know how to use it later
	cout << "\n\n";
	sleep(2);
}

void core::lvl2(core& Core)
{
	cout << "\033]0;" << "Terminal" << "\007";
	system("clear");
	Core.bInteractiveShell = true;
	Core.spawnShell(Core);
	cout << "\n\n";
	system("printf '%s' '\e[32mDaily log, Oct. 10, 2022 ...\e[0m\n' | pv -qL 6");
	sleep(2);
	playerMsg = (" I haven't been feeling like myself lately. I don't know.");
	iterateOverString(playerMsg, 0, 125000000);
	sleep(1);
	cout << "\n\n";
	playerMsg = (" It might have something to do with the fact that I've been sleeping less ...\n");
	iterateOverString(playerMsg, 0, 110000000);
	sleep(1);
	cout << "\n\n";
	playerMsg = (" or maybe it's because we're planning this next big thing and it's just too much\n");
	iterateOverString(playerMsg, 0, 120000000);
	sleep(2);
	cout << "\n\n";
	playerMsg = (" if we really do this, it's going to be a huge risk for all of us\n");
	iterateOverString(playerMsg, 0, 100000000);
	sleep(2);
	cout << "\n\n";
	playerMsg = (" but I realize that we need to help them. If what they think is coming is correct, it's our civic duty to try and prevent it\n");
	iterateOverString(playerMsg, 0, 170000000);
	sleep(1);
	cout << "\n\n";
}