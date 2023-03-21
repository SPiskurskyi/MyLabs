<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3a" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_36" />
        <signal name="XLXN_37" />
        <signal name="XLXN_38" />
        <signal name="XLXN_42" />
        <signal name="XLXN_47" />
        <signal name="XLXN_48" />
        <signal name="XLXN_57" />
        <signal name="XLXN_59" />
        <signal name="XLXN_61" />
        <signal name="XLXN_64" />
        <signal name="XLXN_67" />
        <signal name="XLXN_70" />
        <signal name="XLXN_71" />
        <signal name="XLXN_72" />
        <signal name="XLXN_75" />
        <signal name="XLXN_77" />
        <signal name="XLXN_78" />
        <signal name="XLXN_79" />
        <signal name="XLXN_80" />
        <signal name="OUT_0" />
        <signal name="OUT_1" />
        <signal name="OUT_2" />
        <signal name="OUT_3" />
        <signal name="OUT_4" />
        <signal name="OUT_5" />
        <signal name="IN_0" />
        <signal name="IN_1" />
        <signal name="IN_2" />
        <signal name="IN_3" />
        <signal name="XLXN_44" />
        <signal name="XLXN_101" />
        <port polarity="Output" name="OUT_0" />
        <port polarity="Output" name="OUT_1" />
        <port polarity="Output" name="OUT_2" />
        <port polarity="Output" name="OUT_3" />
        <port polarity="Output" name="OUT_4" />
        <port polarity="Output" name="OUT_5" />
        <port polarity="Input" name="IN_0" />
        <port polarity="Input" name="IN_1" />
        <port polarity="Input" name="IN_2" />
        <port polarity="Input" name="IN_3" />
        <blockdef name="obuf">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="0" y2="-64" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="128" y1="-32" y2="-32" x1="224" />
        </blockdef>
        <blockdef name="and3">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="192" y1="-128" y2="-128" x1="256" />
            <line x2="144" y1="-176" y2="-176" x1="64" />
            <line x2="64" y1="-80" y2="-80" x1="144" />
            <arc ex="144" ey="-176" sx="144" sy="-80" r="48" cx="144" cy="-128" />
            <line x2="64" y1="-64" y2="-192" x1="64" />
        </blockdef>
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <blockdef name="or4">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="48" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="48" y1="-256" y2="-256" x1="0" />
            <line x2="192" y1="-160" y2="-160" x1="256" />
            <arc ex="112" ey="-208" sx="192" sy="-160" r="88" cx="116" cy="-120" />
            <line x2="48" y1="-208" y2="-208" x1="112" />
            <line x2="48" y1="-112" y2="-112" x1="112" />
            <line x2="48" y1="-256" y2="-208" x1="48" />
            <line x2="48" y1="-64" y2="-112" x1="48" />
            <arc ex="48" ey="-208" sx="48" sy="-112" r="56" cx="16" cy="-160" />
            <arc ex="192" ey="-160" sx="112" sy="-112" r="88" cx="116" cy="-200" />
        </blockdef>
        <blockdef name="and4">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-112" y2="-112" x1="144" />
            <arc ex="144" ey="-208" sx="144" sy="-112" r="48" cx="144" cy="-160" />
            <line x2="144" y1="-208" y2="-208" x1="64" />
            <line x2="64" y1="-64" y2="-256" x1="64" />
            <line x2="192" y1="-160" y2="-160" x1="256" />
            <line x2="64" y1="-256" y2="-256" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-64" y2="-64" x1="0" />
        </blockdef>
        <blockdef name="or2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="192" ey="-96" sx="112" sy="-48" r="88" cx="116" cy="-136" />
            <arc ex="48" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <line x2="48" y1="-144" y2="-144" x1="112" />
            <arc ex="112" ey="-144" sx="192" sy="-96" r="88" cx="116" cy="-56" />
            <line x2="48" y1="-48" y2="-48" x1="112" />
        </blockdef>
        <blockdef name="ibuf4">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-224" y2="-224" x1="0" />
            <line x2="128" y1="-160" y2="-160" x1="224" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="64" y1="-192" y2="-256" x1="64" />
            <line x2="64" y1="-224" y2="-192" x1="128" />
            <line x2="128" y1="-256" y2="-224" x1="64" />
            <line x2="64" y1="-128" y2="-192" x1="64" />
            <line x2="64" y1="-160" y2="-128" x1="128" />
            <line x2="128" y1="-192" y2="-160" x1="64" />
            <line x2="64" y1="-64" y2="-128" x1="64" />
            <line x2="64" y1="-96" y2="-64" x1="128" />
            <line x2="128" y1="-128" y2="-96" x1="64" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="128" y1="-32" y2="-32" x1="224" />
            <line x2="64" y1="-96" y2="-96" x1="0" />
            <line x2="64" y1="-160" y2="-160" x1="0" />
            <line x2="128" y1="-224" y2="-224" x1="224" />
            <line x2="128" y1="-96" y2="-96" x1="224" />
        </blockdef>
        <blockdef name="or3">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="48" y1="-64" y2="-64" x1="0" />
            <line x2="72" y1="-128" y2="-128" x1="0" />
            <line x2="48" y1="-192" y2="-192" x1="0" />
            <line x2="192" y1="-128" y2="-128" x1="256" />
            <arc ex="192" ey="-128" sx="112" sy="-80" r="88" cx="116" cy="-168" />
            <arc ex="48" ey="-176" sx="48" sy="-80" r="56" cx="16" cy="-128" />
            <line x2="48" y1="-64" y2="-80" x1="48" />
            <line x2="48" y1="-192" y2="-176" x1="48" />
            <line x2="48" y1="-80" y2="-80" x1="112" />
            <arc ex="112" ey="-176" sx="192" sy="-128" r="88" cx="116" cy="-88" />
            <line x2="48" y1="-176" y2="-176" x1="112" />
        </blockdef>
        <block symbolname="and3" name="XLXI_25">
            <blockpin signalname="XLXN_38" name="I0" />
            <blockpin signalname="XLXN_44" name="I1" />
            <blockpin signalname="XLXN_101" name="I2" />
            <blockpin signalname="XLXN_48" name="O" />
        </block>
        <block symbolname="and3" name="XLXI_34">
            <blockpin signalname="XLXN_37" name="I0" />
            <blockpin signalname="XLXN_42" name="I1" />
            <blockpin signalname="XLXN_80" name="I2" />
            <blockpin signalname="XLXN_57" name="O" />
        </block>
        <block symbolname="or4" name="XLXI_35">
            <blockpin signalname="XLXN_47" name="I0" />
            <blockpin signalname="XLXN_48" name="I1" />
            <blockpin signalname="XLXN_57" name="I2" />
            <blockpin signalname="XLXN_59" name="I3" />
            <blockpin signalname="XLXN_64" name="O" />
        </block>
        <block symbolname="and3" name="XLXI_24">
            <blockpin signalname="XLXN_44" name="I0" />
            <blockpin signalname="XLXN_42" name="I1" />
            <blockpin signalname="XLXN_101" name="I2" />
            <blockpin signalname="XLXN_47" name="O" />
        </block>
        <block symbolname="and4" name="XLXI_36">
            <blockpin signalname="XLXN_80" name="I0" />
            <blockpin signalname="XLXN_36" name="I1" />
            <blockpin signalname="XLXN_44" name="I2" />
            <blockpin signalname="XLXN_61" name="I3" />
            <blockpin signalname="XLXN_59" name="O" />
        </block>
        <block symbolname="and4" name="XLXI_37">
            <blockpin signalname="XLXN_101" name="I0" />
            <blockpin signalname="XLXN_42" name="I1" />
            <blockpin signalname="XLXN_44" name="I2" />
            <blockpin signalname="XLXN_38" name="I3" />
            <blockpin signalname="XLXN_67" name="O" />
        </block>
        <block symbolname="and4" name="XLXI_38">
            <blockpin signalname="XLXN_80" name="I0" />
            <blockpin signalname="XLXN_36" name="I1" />
            <blockpin signalname="XLXN_37" name="I2" />
            <blockpin signalname="XLXN_38" name="I3" />
            <blockpin signalname="XLXN_70" name="O" />
        </block>
        <block symbolname="and4" name="XLXI_39">
            <blockpin signalname="XLXN_101" name="I0" />
            <blockpin signalname="XLXN_42" name="I1" />
            <blockpin signalname="XLXN_44" name="I2" />
            <blockpin signalname="XLXN_61" name="I3" />
            <blockpin signalname="XLXN_71" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_40">
            <blockpin signalname="XLXN_71" name="I0" />
            <blockpin signalname="XLXN_70" name="I1" />
            <blockpin signalname="XLXN_72" name="O" />
        </block>
        <block symbolname="and3" name="XLXI_41">
            <blockpin signalname="XLXN_38" name="I0" />
            <blockpin signalname="XLXN_37" name="I1" />
            <blockpin signalname="XLXN_80" name="I2" />
            <blockpin signalname="XLXN_75" name="O" />
        </block>
        <block symbolname="and4" name="XLXI_42">
            <blockpin signalname="XLXN_101" name="I0" />
            <blockpin signalname="XLXN_42" name="I1" />
            <blockpin signalname="XLXN_37" name="I2" />
            <blockpin signalname="XLXN_61" name="I3" />
            <blockpin signalname="XLXN_77" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_43">
            <blockpin signalname="XLXN_77" name="I0" />
            <blockpin signalname="XLXN_75" name="I1" />
            <blockpin signalname="XLXN_78" name="O" />
        </block>
        <block symbolname="ibuf4" name="XLXI_70">
            <blockpin signalname="IN_0" name="I0" />
            <blockpin signalname="IN_1" name="I1" />
            <blockpin signalname="IN_2" name="I2" />
            <blockpin signalname="IN_3" name="I3" />
            <blockpin signalname="XLXN_80" name="O0" />
            <blockpin signalname="XLXN_36" name="O1" />
            <blockpin signalname="XLXN_37" name="O2" />
            <blockpin signalname="XLXN_38" name="O3" />
        </block>
        <block symbolname="inv" name="XLXI_72">
            <blockpin signalname="XLXN_80" name="I" />
            <blockpin signalname="XLXN_101" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_76">
            <blockpin signalname="XLXN_36" name="I" />
            <blockpin signalname="XLXN_42" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_77">
            <blockpin signalname="XLXN_37" name="I" />
            <blockpin signalname="XLXN_44" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_78">
            <blockpin signalname="XLXN_38" name="I" />
            <blockpin signalname="XLXN_61" name="O" />
        </block>
        <block symbolname="obuf" name="XLXI_79">
            <blockpin signalname="XLXN_64" name="I" />
            <blockpin signalname="OUT_0" name="O" />
        </block>
        <block symbolname="obuf" name="XLXI_80">
            <blockpin signalname="XLXN_80" name="I" />
            <blockpin signalname="OUT_1" name="O" />
        </block>
        <block symbolname="obuf" name="XLXI_81">
            <blockpin signalname="XLXN_67" name="I" />
            <blockpin signalname="OUT_2" name="O" />
        </block>
        <block symbolname="obuf" name="XLXI_82">
            <blockpin signalname="XLXN_72" name="I" />
            <blockpin signalname="OUT_3" name="O" />
        </block>
        <block symbolname="obuf" name="XLXI_83">
            <blockpin signalname="XLXN_78" name="I" />
            <blockpin signalname="OUT_4" name="O" />
        </block>
        <block symbolname="obuf" name="XLXI_84">
            <blockpin signalname="XLXN_79" name="I" />
            <blockpin signalname="OUT_5" name="O" />
        </block>
        <block symbolname="or3" name="XLXI_89">
            <blockpin signalname="XLXN_36" name="I0" />
            <blockpin signalname="XLXN_37" name="I1" />
            <blockpin signalname="XLXN_101" name="I2" />
            <blockpin signalname="XLXN_79" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <branch name="XLXN_36">
            <wire x2="448" y1="848" y2="848" x1="416" />
            <wire x2="512" y1="848" y2="848" x1="448" />
            <wire x2="448" y1="848" y2="1088" x1="448" />
            <wire x2="896" y1="1088" y2="1088" x1="448" />
            <wire x2="1264" y1="1088" y2="1088" x1="896" />
            <wire x2="448" y1="1088" y2="1104" x1="448" />
            <wire x2="1664" y1="1104" y2="1104" x1="448" />
            <wire x2="1664" y1="1104" y2="1680" x1="1664" />
            <wire x2="2208" y1="1680" y2="1680" x1="1664" />
            <wire x2="2400" y1="1680" y2="1680" x1="2208" />
            <wire x2="512" y1="720" y2="848" x1="512" />
            <wire x2="576" y1="720" y2="720" x1="512" />
            <wire x2="768" y1="288" y2="432" x1="768" />
            <wire x2="896" y1="432" y2="432" x1="768" />
            <wire x2="896" y1="432" y2="1088" x1="896" />
            <wire x2="944" y1="288" y2="288" x1="768" />
            <wire x2="1264" y1="352" y2="1088" x1="1264" />
            <wire x2="1792" y1="352" y2="352" x1="1264" />
            <wire x2="2400" y1="1472" y2="1680" x1="2400" />
        </branch>
        <instance x="368" y="416" name="XLXI_25" orien="R0" />
        <instance x="768" y="240" name="XLXI_34" orien="R0" />
        <instance x="1216" y="16" name="XLXI_35" orien="M180" />
        <branch name="XLXN_47">
            <wire x2="688" y1="112" y2="112" x1="624" />
            <wire x2="688" y1="112" y2="192" x1="688" />
            <wire x2="1088" y1="192" y2="192" x1="688" />
            <wire x2="1088" y1="80" y2="192" x1="1088" />
            <wire x2="1216" y1="80" y2="80" x1="1088" />
        </branch>
        <instance x="368" y="240" name="XLXI_24" orien="R0" />
        <branch name="XLXN_57">
            <wire x2="1120" y1="112" y2="112" x1="1024" />
            <wire x2="1120" y1="112" y2="208" x1="1120" />
            <wire x2="1216" y1="208" y2="208" x1="1120" />
        </branch>
        <branch name="XLXN_48">
            <wire x2="704" y1="288" y2="288" x1="624" />
            <wire x2="704" y1="208" y2="288" x1="704" />
            <wire x2="1072" y1="208" y2="208" x1="704" />
            <wire x2="1072" y1="144" y2="208" x1="1072" />
            <wire x2="1216" y1="144" y2="144" x1="1072" />
        </branch>
        <instance x="944" y="160" name="XLXI_36" orien="M180" />
        <branch name="XLXN_59">
            <wire x2="1216" y1="320" y2="320" x1="1200" />
            <wire x2="1216" y1="272" y2="320" x1="1216" />
        </branch>
        <branch name="XLXN_61">
            <wire x2="944" y1="912" y2="912" x1="800" />
            <wire x2="1024" y1="912" y2="912" x1="944" />
            <wire x2="1792" y1="912" y2="912" x1="1024" />
            <wire x2="1024" y1="912" y2="1808" x1="1024" />
            <wire x2="1312" y1="1808" y2="1808" x1="1024" />
            <wire x2="944" y1="416" y2="912" x1="944" />
            <wire x2="1792" y1="816" y2="912" x1="1792" />
        </branch>
        <branch name="XLXN_64">
            <wire x2="2688" y1="176" y2="176" x1="1472" />
            <wire x2="2688" y1="176" y2="688" x1="2688" />
            <wire x2="3040" y1="688" y2="688" x1="2688" />
        </branch>
        <instance x="1280" y="368" name="XLXI_37" orien="M180" />
        <instance x="1792" y="224" name="XLXI_38" orien="M180" />
        <instance x="1792" y="560" name="XLXI_39" orien="M180" />
        <instance x="2368" y="768" name="XLXI_40" orien="R0" />
        <branch name="XLXN_70">
            <wire x2="2208" y1="384" y2="384" x1="2048" />
            <wire x2="2208" y1="384" y2="640" x1="2208" />
            <wire x2="2368" y1="640" y2="640" x1="2208" />
        </branch>
        <branch name="XLXN_71">
            <wire x2="2208" y1="720" y2="720" x1="2048" />
            <wire x2="2208" y1="704" y2="720" x1="2208" />
            <wire x2="2368" y1="704" y2="704" x1="2208" />
        </branch>
        <instance x="1296" y="1536" name="XLXI_41" orien="R0" />
        <instance x="1312" y="1552" name="XLXI_42" orien="M180" />
        <instance x="1680" y="1648" name="XLXI_43" orien="R0" />
        <branch name="XLXN_75">
            <wire x2="1568" y1="1408" y2="1408" x1="1552" />
            <wire x2="1568" y1="1408" y2="1520" x1="1568" />
            <wire x2="1680" y1="1520" y2="1520" x1="1568" />
        </branch>
        <branch name="XLXN_77">
            <wire x2="1616" y1="1712" y2="1712" x1="1568" />
            <wire x2="1616" y1="1584" y2="1712" x1="1616" />
            <wire x2="1680" y1="1584" y2="1584" x1="1616" />
        </branch>
        <branch name="XLXN_79">
            <wire x2="2896" y1="1408" y2="1408" x1="2656" />
            <wire x2="2896" y1="1408" y2="1456" x1="2896" />
            <wire x2="2992" y1="1456" y2="1456" x1="2896" />
            <wire x2="3040" y1="1120" y2="1120" x1="2992" />
            <wire x2="2992" y1="1120" y2="1456" x1="2992" />
        </branch>
        <branch name="XLXN_78">
            <wire x2="1952" y1="1552" y2="1552" x1="1936" />
            <wire x2="3040" y1="1024" y2="1024" x1="1952" />
            <wire x2="1952" y1="1024" y2="1552" x1="1952" />
        </branch>
        <branch name="OUT_0">
            <wire x2="3344" y1="688" y2="688" x1="3264" />
        </branch>
        <branch name="OUT_4">
            <wire x2="3280" y1="1024" y2="1024" x1="3264" />
            <wire x2="3344" y1="1024" y2="1024" x1="3280" />
        </branch>
        <branch name="OUT_5">
            <wire x2="3280" y1="1120" y2="1120" x1="3264" />
            <wire x2="3344" y1="1120" y2="1120" x1="3280" />
        </branch>
        <branch name="OUT_2">
            <wire x2="3280" y1="848" y2="848" x1="3264" />
            <wire x2="3344" y1="848" y2="848" x1="3280" />
        </branch>
        <branch name="OUT_1">
            <wire x2="3344" y1="768" y2="768" x1="3264" />
        </branch>
        <branch name="OUT_3">
            <wire x2="3280" y1="928" y2="928" x1="3264" />
            <wire x2="3344" y1="928" y2="928" x1="3280" />
        </branch>
        <branch name="XLXN_72">
            <wire x2="2640" y1="672" y2="672" x1="2624" />
            <wire x2="2640" y1="672" y2="928" x1="2640" />
            <wire x2="3024" y1="928" y2="928" x1="2640" />
            <wire x2="3040" y1="928" y2="928" x1="3024" />
        </branch>
        <branch name="XLXN_67">
            <wire x2="1552" y1="528" y2="528" x1="1536" />
            <wire x2="2976" y1="528" y2="528" x1="1552" />
            <wire x2="2976" y1="528" y2="848" x1="2976" />
            <wire x2="3024" y1="848" y2="848" x1="2976" />
            <wire x2="3040" y1="848" y2="848" x1="3024" />
        </branch>
        <branch name="XLXN_80">
            <wire x2="432" y1="784" y2="784" x1="416" />
            <wire x2="496" y1="784" y2="784" x1="432" />
            <wire x2="432" y1="784" y2="1056" x1="432" />
            <wire x2="608" y1="1056" y2="1056" x1="432" />
            <wire x2="608" y1="1056" y2="1344" x1="608" />
            <wire x2="1296" y1="1344" y2="1344" x1="608" />
            <wire x2="880" y1="1056" y2="1056" x1="608" />
            <wire x2="880" y1="1056" y2="1232" x1="880" />
            <wire x2="1616" y1="1232" y2="1232" x1="880" />
            <wire x2="2240" y1="1056" y2="1056" x1="880" />
            <wire x2="496" y1="624" y2="784" x1="496" />
            <wire x2="576" y1="624" y2="624" x1="496" />
            <wire x2="640" y1="48" y2="256" x1="640" />
            <wire x2="688" y1="256" y2="256" x1="640" />
            <wire x2="688" y1="256" y2="464" x1="688" />
            <wire x2="752" y1="464" y2="464" x1="688" />
            <wire x2="880" y1="464" y2="464" x1="752" />
            <wire x2="880" y1="464" y2="1056" x1="880" />
            <wire x2="768" y1="48" y2="48" x1="640" />
            <wire x2="752" y1="224" y2="464" x1="752" />
            <wire x2="944" y1="224" y2="224" x1="752" />
            <wire x2="1616" y1="288" y2="1232" x1="1616" />
            <wire x2="1792" y1="288" y2="288" x1="1616" />
            <wire x2="2240" y1="768" y2="1056" x1="2240" />
            <wire x2="3040" y1="768" y2="768" x1="2240" />
        </branch>
        <branch name="XLXN_37">
            <wire x2="464" y1="912" y2="912" x1="416" />
            <wire x2="528" y1="912" y2="912" x1="464" />
            <wire x2="464" y1="912" y2="1120" x1="464" />
            <wire x2="624" y1="1120" y2="1120" x1="464" />
            <wire x2="624" y1="1120" y2="1408" x1="624" />
            <wire x2="1296" y1="1408" y2="1408" x1="624" />
            <wire x2="624" y1="1408" y2="1696" x1="624" />
            <wire x2="624" y1="1696" y2="1744" x1="624" />
            <wire x2="1312" y1="1744" y2="1744" x1="624" />
            <wire x2="912" y1="1120" y2="1120" x1="624" />
            <wire x2="1248" y1="1120" y2="1120" x1="912" />
            <wire x2="2016" y1="1120" y2="1120" x1="1248" />
            <wire x2="2016" y1="1120" y2="1520" x1="2016" />
            <wire x2="2208" y1="1520" y2="1520" x1="2016" />
            <wire x2="2208" y1="1520" y2="1536" x1="2208" />
            <wire x2="2304" y1="1536" y2="1536" x1="2208" />
            <wire x2="528" y1="816" y2="912" x1="528" />
            <wire x2="576" y1="816" y2="816" x1="528" />
            <wire x2="720" y1="176" y2="448" x1="720" />
            <wire x2="912" y1="448" y2="448" x1="720" />
            <wire x2="912" y1="448" y2="1120" x1="912" />
            <wire x2="768" y1="176" y2="176" x1="720" />
            <wire x2="1248" y1="416" y2="1120" x1="1248" />
            <wire x2="1792" y1="416" y2="416" x1="1248" />
            <wire x2="2304" y1="1408" y2="1536" x1="2304" />
            <wire x2="2400" y1="1408" y2="1408" x1="2304" />
        </branch>
        <branch name="XLXN_38">
            <wire x2="144" y1="352" y2="416" x1="144" />
            <wire x2="928" y1="416" y2="416" x1="144" />
            <wire x2="928" y1="416" y2="1152" x1="928" />
            <wire x2="928" y1="1152" y2="1216" x1="928" />
            <wire x2="992" y1="1216" y2="1216" x1="928" />
            <wire x2="1584" y1="1216" y2="1216" x1="992" />
            <wire x2="1200" y1="1152" y2="1152" x1="928" />
            <wire x2="368" y1="352" y2="352" x1="144" />
            <wire x2="480" y1="976" y2="976" x1="416" />
            <wire x2="544" y1="976" y2="976" x1="480" />
            <wire x2="480" y1="976" y2="1152" x1="480" />
            <wire x2="640" y1="1152" y2="1152" x1="480" />
            <wire x2="640" y1="1152" y2="1472" x1="640" />
            <wire x2="688" y1="1472" y2="1472" x1="640" />
            <wire x2="912" y1="1472" y2="1472" x1="688" />
            <wire x2="1296" y1="1472" y2="1472" x1="912" />
            <wire x2="864" y1="1152" y2="1152" x1="640" />
            <wire x2="928" y1="1152" y2="1152" x1="864" />
            <wire x2="544" y1="912" y2="976" x1="544" />
            <wire x2="576" y1="912" y2="912" x1="544" />
            <wire x2="1200" y1="624" y2="1152" x1="1200" />
            <wire x2="1280" y1="624" y2="624" x1="1200" />
            <wire x2="1584" y1="480" y2="1216" x1="1584" />
            <wire x2="1792" y1="480" y2="480" x1="1584" />
        </branch>
        <iomarker fontsize="28" x="3344" y="1024" name="OUT_4" orien="R0" />
        <iomarker fontsize="28" x="3344" y="1120" name="OUT_5" orien="R0" />
        <iomarker fontsize="28" x="3344" y="928" name="OUT_3" orien="R0" />
        <iomarker fontsize="28" x="3344" y="848" name="OUT_2" orien="R0" />
        <iomarker fontsize="28" x="3344" y="768" name="OUT_1" orien="R0" />
        <iomarker fontsize="28" x="3344" y="688" name="OUT_0" orien="R0" />
        <instance x="192" y="1008" name="XLXI_70" orien="R0" />
        <branch name="IN_0">
            <wire x2="192" y1="784" y2="784" x1="160" />
        </branch>
        <iomarker fontsize="28" x="160" y="784" name="IN_0" orien="R180" />
        <branch name="IN_1">
            <wire x2="192" y1="848" y2="848" x1="160" />
        </branch>
        <iomarker fontsize="28" x="160" y="848" name="IN_1" orien="R180" />
        <branch name="IN_2">
            <wire x2="192" y1="912" y2="912" x1="160" />
        </branch>
        <iomarker fontsize="28" x="160" y="912" name="IN_2" orien="R180" />
        <branch name="IN_3">
            <wire x2="192" y1="976" y2="976" x1="160" />
        </branch>
        <iomarker fontsize="28" x="160" y="976" name="IN_3" orien="R180" />
        <branch name="XLXN_42">
            <wire x2="48" y1="112" y2="528" x1="48" />
            <wire x2="832" y1="528" y2="528" x1="48" />
            <wire x2="832" y1="528" y2="672" x1="832" />
            <wire x2="832" y1="672" y2="720" x1="832" />
            <wire x2="992" y1="720" y2="720" x1="832" />
            <wire x2="1168" y1="720" y2="720" x1="992" />
            <wire x2="1664" y1="720" y2="720" x1="1168" />
            <wire x2="992" y1="720" y2="1392" x1="992" />
            <wire x2="992" y1="1392" y2="1680" x1="992" />
            <wire x2="1312" y1="1680" y2="1680" x1="992" />
            <wire x2="240" y1="112" y2="112" x1="48" />
            <wire x2="368" y1="112" y2="112" x1="240" />
            <wire x2="240" y1="16" y2="112" x1="240" />
            <wire x2="752" y1="16" y2="16" x1="240" />
            <wire x2="752" y1="16" y2="112" x1="752" />
            <wire x2="768" y1="112" y2="112" x1="752" />
            <wire x2="816" y1="720" y2="720" x1="800" />
            <wire x2="832" y1="720" y2="720" x1="816" />
            <wire x2="1168" y1="496" y2="720" x1="1168" />
            <wire x2="1280" y1="496" y2="496" x1="1168" />
            <wire x2="1664" y1="688" y2="720" x1="1664" />
            <wire x2="1728" y1="688" y2="688" x1="1664" />
            <wire x2="1744" y1="688" y2="688" x1="1728" />
            <wire x2="1792" y1="688" y2="688" x1="1744" />
        </branch>
        <instance x="576" y="656" name="XLXI_72" orien="R0" />
        <instance x="576" y="752" name="XLXI_76" orien="R0" />
        <instance x="576" y="848" name="XLXI_77" orien="R0" />
        <instance x="576" y="944" name="XLXI_78" orien="R0" />
        <instance x="3040" y="656" name="XLXI_79" orien="M180" />
        <instance x="3040" y="736" name="XLXI_80" orien="M180" />
        <instance x="3040" y="816" name="XLXI_81" orien="M180" />
        <instance x="3040" y="896" name="XLXI_82" orien="M180" />
        <instance x="3040" y="992" name="XLXI_83" orien="M180" />
        <instance x="3040" y="1088" name="XLXI_84" orien="M180" />
        <branch name="XLXN_44">
            <wire x2="368" y1="176" y2="176" x1="64" />
            <wire x2="64" y1="176" y2="288" x1="64" />
            <wire x2="64" y1="288" y2="496" x1="64" />
            <wire x2="816" y1="496" y2="496" x1="64" />
            <wire x2="848" y1="496" y2="496" x1="816" />
            <wire x2="848" y1="496" y2="720" x1="848" />
            <wire x2="848" y1="720" y2="816" x1="848" />
            <wire x2="1184" y1="816" y2="816" x1="848" />
            <wire x2="1376" y1="816" y2="816" x1="1184" />
            <wire x2="1488" y1="816" y2="816" x1="1376" />
            <wire x2="368" y1="288" y2="288" x1="64" />
            <wire x2="848" y1="816" y2="816" x1="800" />
            <wire x2="816" y1="352" y2="496" x1="816" />
            <wire x2="944" y1="352" y2="352" x1="816" />
            <wire x2="1184" y1="560" y2="816" x1="1184" />
            <wire x2="1280" y1="560" y2="560" x1="1184" />
            <wire x2="1488" y1="752" y2="816" x1="1488" />
            <wire x2="1792" y1="752" y2="752" x1="1488" />
        </branch>
        <branch name="XLXN_101">
            <wire x2="368" y1="48" y2="48" x1="32" />
            <wire x2="32" y1="48" y2="224" x1="32" />
            <wire x2="32" y1="224" y2="560" x1="32" />
            <wire x2="816" y1="560" y2="560" x1="32" />
            <wire x2="816" y1="560" y2="624" x1="816" />
            <wire x2="976" y1="624" y2="624" x1="816" />
            <wire x2="1152" y1="624" y2="624" x1="976" />
            <wire x2="1152" y1="624" y2="688" x1="1152" />
            <wire x2="1600" y1="688" y2="688" x1="1152" />
            <wire x2="976" y1="624" y2="1328" x1="976" />
            <wire x2="976" y1="1328" y2="1616" x1="976" />
            <wire x2="1312" y1="1616" y2="1616" x1="976" />
            <wire x2="2000" y1="1328" y2="1328" x1="976" />
            <wire x2="2208" y1="1328" y2="1328" x1="2000" />
            <wire x2="2400" y1="1328" y2="1328" x1="2208" />
            <wire x2="2400" y1="1328" y2="1344" x1="2400" />
            <wire x2="368" y1="224" y2="224" x1="32" />
            <wire x2="816" y1="624" y2="624" x1="800" />
            <wire x2="1152" y1="432" y2="624" x1="1152" />
            <wire x2="1280" y1="432" y2="432" x1="1152" />
            <wire x2="1600" y1="624" y2="688" x1="1600" />
            <wire x2="1792" y1="624" y2="624" x1="1600" />
        </branch>
        <instance x="2400" y="1536" name="XLXI_89" orien="R0" />
    </sheet>
</drawing>