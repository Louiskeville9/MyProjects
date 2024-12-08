import random


class GameParticipant:
    """Class for game participents which is the superclass for this program"""
    def __init__(self, name, balance):
        self.name = name
        self.balance = balance


class Player(GameParticipant):
    """Class for game players which is the childclass of GameParticipant for this program"""
    def __init__(self, name, balance, age):
        super().__init__(name, balance)
        self.age = age
        self.bet = int(input("Please enter bet amount (Integer): "))
        self.option = input("Please enter cho or han: ")

    def change_bet(self):
        """If user wants to add a new bet you can call this function"""
        new_bet = int(input("Please enter new bet (Integer): "))
        new_option = input("Please enter cho or han: ")

        if new_bet > 0:
            self.bet = new_bet #Update the bet
            self.option = new_option
        else:
            print(f"A bet of {self.bet} is not allowed")

    def play_game(self, game_result):
        """Main function to handel the game logic and display the result to the user, the game result returned from the DiceCup class is passed as the result for the game"""
        if self.age >= 18:
            # If the result is the same as the option entered by the user (Win)
            if game_result == self.option:
                self.bet = self.bet * 2
                self.balance = self.balance + self.bet
                print(f"You win: Winnings (${self.bet}) - New Balance = ${self.balance}")
            else:
                # If the result is not the same as the option entered by the user (Lose)
                self.balance = self.balance - self.bet
                print(f"You Lose: Bet Lost | Balance = ${self.balance}")
        else:
            # Catch any players that aren't legally old enough to place bets
            print("You must be 18 years or  older to place bets")


class DiceCup:
    """Creates a result for the game to run off. Returns 'cho' if the result of adding the 2 die is even and 'han' if odd"""
    def __init__(self):
        self.dice1 = random.randint(1, 6)
        self.dice2 = random.randint(1, 6)

    def result(self):
        # Calculate the result of the sum of both dices
        sum_of_dice = self.dice1 + self.dice2

        result = sum_of_dice % 2 # Find remainder, if == 0 then even

        if result == 0: # If result is even return 'cho'
            return "cho"
        else:
            return "han" # If result is uneven return 'han'


# Main code block
attempts = 5
player1 = Player("Louis", 100, 20)

while attempts > 0:
    print(f"Attempts left ({attempts})")

    dice = DiceCup()

    result = dice.result()

    player1.play_game(result)

    attempts = attempts - 1

    if attempts >= 1:
        player1.change_bet()

print(f"Thanks for playing {player1.name}, new balance: ${player1.balance}")





