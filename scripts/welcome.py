"""
Sends a welcome message to players
"""

from cuwo.script import ServerScript, command
from twisted.internet import reactor


class WelcomeServer(ServerScript):
    connection_class = None

    def on_load(self):
        self.welcome = self.server.format_lines(self.server.config.welcome)

    def on_join(self, player):
        player.send_lines(self.server.config.welcome)
        player.send_lines(self.server.config.help_players)


def get_class():
    return WelcomeServer
