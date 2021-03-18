#!/usr/bin/perl

use warnings;
use strict;

sub print_introduction {
	my $difficulty_level = scalar(@_);
	print "_________________________________________________________________________________________________________\n";
	print "\\__    ___/______   ____ _____    ________ _________   ____    /   |   \\ __ __  _____/  |_  ___________\n";
	print "  |    |  \\_  __ \\_/ __ \\__  \\  /  ___/  |  \\_  __ \\_/ __ \\  /    ~    \\  |  \\/    \\   __\\/ __ \\_  __ \\\n";
	print "  |    |   |  | \\/\\  ___/ / __ \\_\\___ \\|  |  /|  | \\/\\  ___/  \\    Y    /  |  /   |  \\  | \\  ___/|  | \\/\n";
	print "  |____|   |__|    \\___  >____  /____  >____/ |__|    \\___  >  \\___|_  /|____/|___|  /__|  \\___  >__|   \n";
	print "                       \\/     \\/     \\/                   \\/         \\/            \\/          \\/       \n";
	print "----------------------------------------------------------------------------------------\n";
	print "You're now the hero trying to get a katana by unlocking the treasure code\n";
	print "You're breaking treasure level", $difficulty_level , "\n";
	print "Enter the correct code to continue...\n";
}

sub game_playing {
	my $difficulty_level = scalar(@_);
	print_introduction($difficulty_level);
	
	my constant $code_A = int(rand($difficulty_level)) + $difficulty_level;
	my constant $code_B = int(rand($difficulty_level)) + $difficulty_level;
	my constant $code_C = int(rand($difficulty_level)) + $difficulty_level;
	
    my constant $code_sum = $code_A + $code_B + $code_C;
	my constant $code_product = $code_A * $code_B * $code_C;
	
	print "There are 3 numbers in the code\n";
	print "The codes add-up to: $code_sum\n";
	print "The codes CodeProduct to: $code_product\n";
	
	print "Enter code to break the level: \n";
	my $guess_A = <STDIN>;
	my $guess_B = <STDIN>;
	my $guess_C = <STDIN>;
	print "You have entered: $guess_A $guess_B $guess_C";
	
	my $guess_sum = $guess_A + $guess_B + $guess_C;
    my $guess_product = $guess_A * $guess_B * $guess_C;
	
	if ($code_sum == $guess_sum && $code_product == $guess_product) {
		print "You win!\n";
		print "****Moving to the next level...\n";
		return 1;
	}
	else {
		print "You lose!\n";
		print "****Reconquering the current level...\n";
		return 0;
	}
	
}

my $level_difficulty = 1;
my $maximum_level = 7;
while ($level_difficulty <= $maximum_level) {
	my $level_complete = game_playing($level_difficulty);
	if ($level_complete == 1) {
		++$level_difficulty;
	}
}
print "CONGRATULATION! YOU HAVE UNLOCKED THE SUPER SAMURAI KATANA!\n";
print " __-----_________________{]___________________________________________________\n";
print "{&&&&&&&#%%&#%&%&%&%&%#%&|]__________________________________________________/\n";
print "                         {]\n";
