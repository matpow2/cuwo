"""
Sends a welcome message to players
"""

from cuwo.script import ServerScript, command
from twisted.internet import reactor


class WelcomeServer(ServerScript):
    connection_class = None

    def on_load(self):
        self.welcome = self.server.format_lines(self.server.config.welcome)
        return True

    def on_new_connection(self, player):
        if not self.welcome:
            return
        player.send_lines(self.welcome)
        if not self.server.config.help_players:
            return
        reactor.callLater(5000, player.send_lines, self.server.config.help_players)
        return True

def get_class():
    return WelcomeServer
