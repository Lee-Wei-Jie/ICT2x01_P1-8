from main import app
from main import splitLines
import pytest


def test_home_page(client):
    response = client.get('/')
    assert response.status_code == 200

def test_play_page(client):
    response = client.get('/play')
    assert response.status_code == 200

def test_play_page_splitLines_withoutinstr():
    instr = " "
    assert "invalid" == splitLines(instr)

def test_play_page_splitLines_withwronginstr():
    instr = "Move"
    assert "invalid" == splitLines(instr)

def test_play_page_splitLines_withinstr1F():
    instr = "Move Forward"
    assert " F" == splitLines(instr)

def test_play_page_splitLines_withinstr1B():
    instr = "Move Backward"
    assert " B" == splitLines(instr)

def test_play_page_splitLines_withinstr1L():
    instr = "Turn Left"
    assert " L" == splitLines(instr)

def test_play_page_splitLines_withinstr1R():
    instr = "Turn Right"
    assert " R" == splitLines(instr)

def test_play_page_splitLines_withinstr2F():
    instr = "Move Forward\r\nMove Forward"
    assert " FF" == splitLines(instr)

def test_play_page_splitLines_withinstr1F1L():
    instr = "Move Forward\r\nTurn Left"
    assert " FL" == splitLines(instr)

def test_play_page_splitLines_withinstr2F():
    instr = "Move Forward\r\nMove Forward"
    assert " FF" == splitLines(instr)

def test_play_page_splitLines_withinstr1B1R():
    instr = "Move Backward\r\nTurn Right"
    assert " BR" == splitLines(instr)

def test_challenge_page(client):
    response = client.get('/challenge')
    assert response.status_code == 200

def test_design_page(client):
    response = client.get('/design')
    assert response.status_code == 200

def test_list_page(client):
    response = client.get('/list')
    assert response.status_code == 200


@pytest.fixture
def client():
    client = app.test_client()
    return client
