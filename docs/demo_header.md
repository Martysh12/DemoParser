# `.dem` Header Structure

## Definitions
`MAX_OSPATH` = **260**

## Structure

| field           | type     | length       | description                                                 |
| --------------- | -------- | ------------ | ----------------------------------------------------------- |
| filestamp       | `char *` | 8            | in valid demo files, this string should be `HL2DEMO\x00`    |
| demoProtocol    | `int`    | 4            | version number of the source demo format                    |
| networkProtocol | `int`    | 4            | version number of the network protocol                      |
| serverName      | `char *` | `MAX_OSPATH` | name of the server (usually just IP address)                |
| clientName      | `char *` | `MAX_OSPATH` | name of the player recording (player name, or `SourceTV`)   |
| mapName         | `char *` | `MAX_OSPATH` | name of the map the demo was played on                      |
| gameDirectory   | `char *` | `MAX_OSPATH` | short game directory, `tf` in case of Team Fortress         |
| playbackTime    | `float`  | 4            | demo playback time, in seconds                              |
| playbackTicks   | `int`    | 4            | demo playback time, in ticks                                |
| playbackFrames  | `int`    | 4            | demo playback time, in frames                               |
| signOnLength    | `int`    | 4            | length of the sign-on data, i don't know what it's used for |